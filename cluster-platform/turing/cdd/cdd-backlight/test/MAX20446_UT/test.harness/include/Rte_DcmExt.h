/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte_DcmExt.h
 *        Config:  iMX8.dpa
 *   ECU-Project:  METER
 *
 *     Generator:  MICROSAR RTE Generator Version 4.16.0
 *                 RTE Core Version 1.16.0
 *       License:  Unlimited license CBD1700905 for Visteon Electronics Germany GmbH
 *
 *   Description:  Application header file for SW-C <DcmExt>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_DCMEXT_H
# define _RTE_DCMEXT_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_DcmExt_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootMagicFlag_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacAppCount; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacFotaCount; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacRollbackCount; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CoherencyDTCState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerHWReference_number; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerReference2_number; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerReference_number; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fingerprint; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FotaUpdateStatus_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FotaUpdateStatus_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_ActivePartition; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Att_Cnt; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_CancelCounter; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Correlator_Id; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_DecryptionResult; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_F_virgin; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_HashValueUpdate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_IVectorData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_IncrementalCounter; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Mileage_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_PreviousState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RemainingDataSize; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RollbackInprogress; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_State; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Virgin_Flag; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ManufacturingModeRequested; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AlertSetting_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_KeyId; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Key_Link_status; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_night_step_User; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_night_step_key; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Customer_reference; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_NvM_Version_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PCBSerialNum; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SMDPlantNum; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_XFuelValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_YFuelValue; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ProgLimitCntr; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_SecurebootCount; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Signature; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Signature_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ValidDTCState; /* PRQA S 0850 */ /* MD_MSR_19.8 */
extern VAR(UInt8, RTE_VAR_INIT) Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ValidDTCState_1; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_BootMagicFlag_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CmacAppCount (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CmacFotaCount (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CmacRollbackCount (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CoherencyDTCState (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CustomerHWReference_number (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CustomerReference2_number (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_CustomerReference_number (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fingerprint (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_1 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_ActivePartition (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_Att_Cnt (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_CancelCounter (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_Correlator_Id (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_DecryptionResult (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_F_virgin (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_HashValueUpdate (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_IVectorData (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_IncrementalCounter (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_Mileage_Flag (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_PreviousState (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_RemainingDataSize (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_RollbackInprogress (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_State (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_Virgin_Flag (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_ManufacturingModeRequested (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_AlertSetting_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_KeyId (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Key_Link_status (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_User (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_key (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Customer_reference (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_NvM_Version_Value (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PCBSerialNum (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SMDPlantNum (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_XFuelValue (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_YFuelValue (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_ProgLimitCntr (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_SecurebootCount (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Signature (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_Signature_1 (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_ValidDTCState (0U)
#  define Rte_InitValue_rp_SR_JobStatus_JobStatus_ValidDTCState_1 (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootApplicationRandomNumber_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootForcedLoaderModeDetected_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BootMagicFlag_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootMagicFlag_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootMagicFlag_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootMagicFlag_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_BootVehicleStateDetected_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CmacAppCount Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CmacAppCount
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CmacAppCount(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacAppCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CmacFotaCount Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CmacFotaCount
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CmacFotaCount(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacFotaCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CmacRollbackCount Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CmacRollbackCount
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CmacRollbackCount(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CmacRollbackCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CoherencyDTCState Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CoherencyDTCState
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CoherencyDTCState(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CoherencyDTCState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CustomerHWReference_number Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CustomerHWReference_number
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CustomerHWReference_number(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerHWReference_number, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CustomerReference2_number Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CustomerReference2_number
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CustomerReference2_number(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerReference2_number, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_CustomerReference_number Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CustomerReference_number
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_CustomerReference_number(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_CustomerReference_number, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUCompatibilityDTCState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ECUGeneralMemoryFailureDTCState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fingerprint Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fingerprint
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fingerprint(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fingerprint, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FotaUpdateStatus_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_FotaUpdateStatus_1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_FotaUpdateStatus_1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_ActivePartition Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_ActivePartition
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_ActivePartition(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_ActivePartition, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_Att_Cnt Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Att_Cnt
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Att_Cnt(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Att_Cnt, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_CancelCounter Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_CancelCounter
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_CancelCounter(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_CancelCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_ConfigurationSignatureError, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_Correlator_Id Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Correlator_Id
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Correlator_Id(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Correlator_Id, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_DecryptionResult Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_DecryptionResult
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_DecryptionResult(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_DecryptionResult, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_F_virgin Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_F_virgin
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_F_virgin(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_F_virgin, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_FlashCompletedAddress, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_GipDtcUpdate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_GlobalDtcUpdate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_HashValueUpdate Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_HashValueUpdate
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_HashValueUpdate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_HashValueUpdate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_IVectorData Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_IVectorData
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_IVectorData(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_IVectorData, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_IncrementalCounter Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_IncrementalCounter
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_IncrementalCounter(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_IncrementalCounter, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_Mileage_Flag Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Mileage_Flag
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Mileage_Flag(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Mileage_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_PreviousState Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_PreviousState
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_PreviousState(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_PreviousState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RebootCompleteFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_RemainingDataSize Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RemainingDataSize
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RemainingDataSize(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RemainingDataSize, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RollbackCompleteFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_RollbackInprogress Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RollbackInprogress
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_RollbackInprogress(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_RollbackInprogress, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_State Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_State
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_State(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_State, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VIPDownloadSkipFlag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VipDtcUpdate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_Virgin_Flag Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Virgin_Flag
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_Virgin_Flag(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_Virgin_Flag, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fota_VlanOpenStatus, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_A_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_A_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_B_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_B_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_C_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_C_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_D_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_D_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_E_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_E_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_H_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_H_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_I_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_I_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_J_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_J_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_K_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_K_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_L_FLPS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Fuel_Table_L_RADS, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_GeneralMemoryFailureDTCState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_AlertSetting_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Car_color_Eco_Welcome_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Key_Link_UserLogin, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Lang_Navi_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte1_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Main_menu_Select_byte2_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_OperationGuidance_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_PersonalDisplay_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_TPMS_Temp_unit_setting_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_Top_layer_contents_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_illum_mode_step_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Gust_NVM_illum_night_step_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_IllumMeasuredMaxIntensity, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_IllumReferenceMaxIntensity, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_ManufacturingModeRequested Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ManufacturingModeRequested
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ManufacturingModeRequested(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ManufacturingModeRequested, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AlertSettingSave_Key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_AlertSetting_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_AlertSetting_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_AlertSetting_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_AlertSetting_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Car_color_Eco_Welcome_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_HM_FaultCounters_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_KeyId Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_KeyId
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_KeyId(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_KeyId, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Key_Link_UserLogin, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Key_Link_status Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Key_Link_status
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Key_Link_status(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Key_Link_status, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Lang_Navi_Ikey_link_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Lang_Navi_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte1_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Main_menu_Select_byte2_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Milage_TPMS_Temp_unit_setting_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_OperationGuidance_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Operation_Guidance_Key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_PersonalDisplay_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Personal_Display_Key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Sound_Channel_Vol, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Sound_Mixer_Op_Vol, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_Top_layer_contents_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_mode_step_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_mode_step_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_User Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_User
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_User(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_night_step_User, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_key Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_key
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NVM_illum_night_step_key(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NVM_illum_night_step_key, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Analog_Measurements_Calibration, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_AssemblyPlantNum, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Assembly_Manufacturing_date, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Customer_reference Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Customer_reference
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Customer_reference(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Customer_reference, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_100_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_200_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_300_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_310_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_400_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_410_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_420_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_430_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_440_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_450_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_500_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_900_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F190_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_F1A2_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_DIAG_DID_FE11_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Correction_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Ect_Gauge_Mapping_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_EquippedPCBVisteonPartNum, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Correction_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Fuel_Gauge_Mapping_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_CltData, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Idle_StopSetting_VltData, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_NvM_Revision_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_NvM_Version_Value Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_NvM_Version_Value
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_NvM_Version_Value(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_NvM_Version_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value3, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value4, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Odo_Running_Count_Value5, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PCBSerialNum Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PCBSerialNum
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PCBSerialNum(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PCBSerialNum, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMBigLeftPointerCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMBigRightPointerCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMLeftDialCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMRightDialCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMSmallLeftPointerCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMSmallRightPointerCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibration, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_PWMTFTBLCalibrationGain, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_ProductVisteonPartNum, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Correction_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_RPM_Gauge_Mapping_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Reset_Counters_Reading, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SMDPlantNum Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SMDPlantNum
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SMDPlantNum(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SMDPlantNum, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaDataIndexArray, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaNumberValueNoTrigger, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_10, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_11, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_12, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_13, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_14, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_15, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_3, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_4, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_5, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_6, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_7, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_8, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_Data_9, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_10, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_11, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_12, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_13, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_14, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_15, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_3, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_4, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_5, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_6, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_7, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_8, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaSSD_TimeData_9, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaStoreNoTriggerDTCIndex, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaStoreTriggerDTCIndex, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaTriggerNumberValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_0, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_10, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_11, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_12, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_13, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_14, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_15, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_3, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_4, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_5, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_6, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_7, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_8, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_SigmaVTD_Data_9, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Correction_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_X, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Spd_Gauge_Mapping_Table_Y, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_AC, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FC, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_FCT, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_ICT, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Traceability_Bytes_WS2, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_VehicleManufacturerSparePartNumberVIP, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_Visteon_Product_Config_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_XFuelValue Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_XFuelValue
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_XFuelValue(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_XFuelValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_YFuelValue Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_YFuelValue
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_YFuelValue(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_YFuelValue, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_NV_vehicleManufacturerECUHardwareNumber, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Max, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V1Min, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Max, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V2Min, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3Min, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_AccelGuideSpeed_V3max, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_DayMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Dial_NightMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRank_T1Min_Time, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E1_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E2_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E3_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_EcoRate_E4_Value, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_CANOut_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Extern_Illum_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_DayMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_Pointer_NightMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_RearDoorAlert_T1_Time, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_DayMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_SideSw_NightMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_DayMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_A_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Nv_TFT_NightMode_Type_B_duty, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_PCB_serial_number_AssemblymanufDate, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_ProgLimitCntr Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ProgLimitCntr
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ProgLimitCntr(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ProgLimitCntr, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Reserved_Health_Management_Data, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_SecurebootCount Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_SecurebootCount
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_SecurebootCount(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_SecurebootCount, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Signature Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Signature
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Signature(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Signature, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_Signature_1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Signature_1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_Signature_1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_Signature_1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_ValidDTCState Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ValidDTCState
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ValidDTCState(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ValidDTCState, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_JobStatus_JobStatus_ValidDTCState_1 Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ValidDTCState_1
#  define Rte_Read_DcmExt_rp_SR_JobStatus_JobStatus_ValidDTCState_1(data) (*(data) = Rte_MemAbstractMdl_pp_SR_JobStatus_JobStatus_ValidDTCState_1, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DCM_APP_APPL_CODE) Dcm_App_ClearDTCRequest(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_ClearDTCRequest() (Dcm_App_ClearDTCRequest(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DCM_APP_APPL_CODE) Dcm_App_ClearDTC_Finish_Request(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_ClearDTC_Finish_Request() (Dcm_App_ClearDTC_Finish_Request(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DCM_APP_APPL_CODE) Dcm_App_DIDOperation(UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pData, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pStatus, teDIDOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_DIDOperation(arg1, arg2, arg3, arg4) (Dcm_App_DIDOperation(arg1, arg2, arg3, arg4), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCM_APP_APPL_CODE) Dcm_App_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc, teDIDOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_DID_DiagAction Dcm_App_DID_DiagAction
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DCM_APP_APPL_CODE) Dcm_App_DTCOperation(UInt32 DTCEventId, teDTCOperation Operation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_DTCOperation(arg1, arg2) (Dcm_App_DTCOperation(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCM_APP_APPL_CODE) Dcm_App_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Out_RoutineInfo, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) Data, P2VAR(UInt16, AUTOMATIC, RTE_DCM_APP_APPL_VAR) DataLength, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pNrc, teRoutineOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_RID_DiagAction Dcm_App_RID_DiagAction
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DCM_APP_APPL_CODE) Dcm_App_RoutineOperation(UInt16 RoutineId, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pInData, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pOutData, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) pStatus, teRoutineOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_RoutineOperation(arg1, arg2, arg3, arg4, arg5) (Dcm_App_RoutineOperation(arg1, arg2, arg3, arg4, arg5), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_DCM_APP_APPL_CODE) Dcm_App_SessionChangeNotification(tDiagSessionSt CurrentSession, UInt8 Sreason); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_SessionChangeNotification(arg1, arg2) (Dcm_App_SessionChangeNotification(arg1, arg2), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCM_APP_APPL_CODE) Dcm_App_SessionChangeValidation(P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) NewSession); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_CS_DcmExt_Diagnostics_SessionChangeValidation Dcm_App_SessionChangeValidation
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCM_APP_APPL_CODE) Dcm_App_DcmApp_FotaServiceEntryNotification(UInt8 SID, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) RequestData, UInt16 DataSize, UInt8 ReqType, UInt16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpFotaServiceEntryNotification_DcmApp_FotaServiceEntryNotification Dcm_App_DcmApp_FotaServiceEntryNotification
#  define RTE_START_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_DCM_APP_APPL_CODE) Dcm_App_DiagEnterystatus(UInt8 SID, P2VAR(UInt8, AUTOMATIC, RTE_DCM_APP_APPL_VAR) RequestData, UInt16 DataSize, UInt8 ReqType, UInt16 SourceAddress, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCM_APP_APPL_VAR) ErrorCode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_DCM_APP_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpGetDiagEnteryCondSts_DiagEnterystatus Dcm_App_DiagEnterystatus
#  define RTE_START_SEC_SECURITYHANDER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_SECURITYHANDER_APPL_CODE) SecurityHander_GetSecurity_KeyIndex(P2VAR(ESecurityKey, AUTOMATIC, RTE_SECURITYHANDER_APPL_VAR) KeyIndex); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_SECURITYHANDER_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpGetSecKeyIndex_GetSecurity_KeyIndex(arg1) (SecurityHander_GetSecurity_KeyIndex(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CMEETCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CMEETCDD_APPL_CODE) CMeetCdd_DID_DiagAction(teDiagOpStatus OpStatus, UInt16 DIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pNrc, teDIDOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CMEETCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_DID_DiagAction_DID_DiagAction CMeetCdd_DID_DiagAction
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BootApplicationRandomNumber_0(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BootApplicationRandomNumber_0 MemAbstractMdl_Get_BootApplicationRandomNumber_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BootForcedLoaderModeDetected_0(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BootForcedLoaderModeDetected_0 MemAbstractMdl_Get_BootForcedLoaderModeDetected_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BootMagicFlag_0(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BootMagicFlag_0(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BootMagicFlag_0 MemAbstractMdl_Get_BootMagicFlag_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_BootVehicleStateDetected_0(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_BootVehicleStateDetected_0 MemAbstractMdl_Get_BootVehicleStateDetected_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CmacAppCount(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CmacAppCount MemAbstractMdl_Get_CmacAppCount
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CmacFotaCount(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CmacFotaCount MemAbstractMdl_Get_CmacFotaCount
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CmacRollbackCount(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CmacRollbackCount MemAbstractMdl_Get_CmacRollbackCount
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CoherencyDTCState(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CoherencyDTCState MemAbstractMdl_Get_CoherencyDTCState
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CustomerHWReference_number(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CustomerHWReference_number(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CustomerHWReference_number MemAbstractMdl_Get_CustomerHWReference_number
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CustomerReference2_number(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CustomerReference2_number(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CustomerReference2_number MemAbstractMdl_Get_CustomerReference2_number
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CustomerReference_number(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_CustomerReference_number(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_CustomerReference_number MemAbstractMdl_Get_CustomerReference_number
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ECUCompatibilityDTCState(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_ECUCompatibilityDTCState MemAbstractMdl_Get_ECUCompatibilityDTCState
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ECUGeneralMemoryFailureDTCState(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_ECUGeneralMemoryFailureDTCState MemAbstractMdl_Get_ECUGeneralMemoryFailureDTCState
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fingerprint(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fingerprint(P2VAR(t_uint8_x_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fingerprint MemAbstractMdl_Get_Fingerprint
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_FotaUpdateStatus_0(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_FotaUpdateStatus_0(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_FotaUpdateStatus_0 MemAbstractMdl_Get_FotaUpdateStatus_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_FotaUpdateStatus_1(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_FotaUpdateStatus_1(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_FotaUpdateStatus_1 MemAbstractMdl_Get_FotaUpdateStatus_1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_ActivePartition(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_ActivePartition MemAbstractMdl_Get_Fota_ActivePartition
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_Att_Cnt(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_Att_Cnt MemAbstractMdl_Get_Fota_Att_Cnt
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_CancelCounter(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_CancelCounter MemAbstractMdl_Get_Fota_CancelCounter
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_ConfigurationSignatureError(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_ConfigurationSignatureError(P2VAR(t_uint8_x_6, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_ConfigurationSignatureError MemAbstractMdl_Get_Fota_ConfigurationSignatureError
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_Correlator_Id(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_Correlator_Id(P2VAR(t_uint8_x_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_Correlator_Id MemAbstractMdl_Get_Fota_Correlator_Id
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_DecryptionResult(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_DecryptionResult(P2VAR(t_uint8_x_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_DecryptionResult MemAbstractMdl_Get_Fota_DecryptionResult
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_F_virgin(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_F_virgin MemAbstractMdl_Get_Fota_F_virgin
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_FlashCompletedAddress(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_FlashCompletedAddress MemAbstractMdl_Get_Fota_FlashCompletedAddress
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_GipDtcUpdate(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_GipDtcUpdate MemAbstractMdl_Get_Fota_GipDtcUpdate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_GlobalDtcUpdate(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_GlobalDtcUpdate MemAbstractMdl_Get_Fota_GlobalDtcUpdate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_HashValueUpdate(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_HashValueUpdate(P2VAR(t_uint8_x_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_HashValueUpdate MemAbstractMdl_Get_Fota_HashValueUpdate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_IVectorData(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_IVectorData(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_IVectorData MemAbstractMdl_Get_Fota_IVectorData
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_IncrementalCounter(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_IncrementalCounter(P2VAR(t_uint8_x_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_IncrementalCounter MemAbstractMdl_Get_Fota_IncrementalCounter
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_Mileage_Flag(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_Mileage_Flag MemAbstractMdl_Get_Fota_Mileage_Flag
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_PreviousState(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_PreviousState MemAbstractMdl_Get_Fota_PreviousState
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_RebootCompleteFlag(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_RebootCompleteFlag MemAbstractMdl_Get_Fota_RebootCompleteFlag
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_RemainingDataSize(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_RemainingDataSize MemAbstractMdl_Get_Fota_RemainingDataSize
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_RollbackCompleteFlag(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_RollbackCompleteFlag MemAbstractMdl_Get_Fota_RollbackCompleteFlag
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_RollbackInprogress(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_RollbackInprogress MemAbstractMdl_Get_Fota_RollbackInprogress
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_State(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_State MemAbstractMdl_Get_Fota_State
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_VIPDownloadSkipFlag(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_VIPDownloadSkipFlag MemAbstractMdl_Get_Fota_VIPDownloadSkipFlag
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_VipDtcUpdate(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_VipDtcUpdate MemAbstractMdl_Get_Fota_VipDtcUpdate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_Virgin_Flag(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_Virgin_Flag MemAbstractMdl_Get_Fota_Virgin_Flag
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fota_VlanOpenStatus(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fota_VlanOpenStatus MemAbstractMdl_Get_Fota_VlanOpenStatus
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_A_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_A_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_A_FLPS MemAbstractMdl_Get_Fuel_Table_A_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_A_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_A_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_A_RADS MemAbstractMdl_Get_Fuel_Table_A_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_B_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_B_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_B_FLPS MemAbstractMdl_Get_Fuel_Table_B_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_B_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_B_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_B_RADS MemAbstractMdl_Get_Fuel_Table_B_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_C_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_C_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_C_FLPS MemAbstractMdl_Get_Fuel_Table_C_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_C_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_C_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_C_RADS MemAbstractMdl_Get_Fuel_Table_C_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_D_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_D_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_D_FLPS MemAbstractMdl_Get_Fuel_Table_D_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_D_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_D_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_D_RADS MemAbstractMdl_Get_Fuel_Table_D_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_E_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_E_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_E_FLPS MemAbstractMdl_Get_Fuel_Table_E_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_E_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_E_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_E_RADS MemAbstractMdl_Get_Fuel_Table_E_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_H_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_H_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_H_FLPS MemAbstractMdl_Get_Fuel_Table_H_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_H_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_H_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_H_RADS MemAbstractMdl_Get_Fuel_Table_H_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_I_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_I_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_I_FLPS MemAbstractMdl_Get_Fuel_Table_I_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_I_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_I_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_I_RADS MemAbstractMdl_Get_Fuel_Table_I_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_J_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_J_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_J_FLPS MemAbstractMdl_Get_Fuel_Table_J_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_J_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_J_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_J_RADS MemAbstractMdl_Get_Fuel_Table_J_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_K_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_K_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_K_FLPS MemAbstractMdl_Get_Fuel_Table_K_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_K_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_K_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_K_RADS MemAbstractMdl_Get_Fuel_Table_K_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_L_FLPS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_L_FLPS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_L_FLPS MemAbstractMdl_Get_Fuel_Table_L_FLPS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_L_RADS(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Fuel_Table_L_RADS(P2VAR(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Fuel_Table_L_RADS MemAbstractMdl_Get_Fuel_Table_L_RADS
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_GeneralMemoryFailureDTCState(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_GeneralMemoryFailureDTCState MemAbstractMdl_Get_GeneralMemoryFailureDTCState
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_AlertSetting_User(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_AlertSetting_User MemAbstractMdl_Get_Gust_NVM_AlertSetting_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_Car_color_Eco_Welcome_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_Car_color_Eco_Welcome_User MemAbstractMdl_Get_Gust_NVM_Car_color_Eco_Welcome_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_Key_Link_UserLogin(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_Key_Link_UserLogin MemAbstractMdl_Get_Gust_NVM_Key_Link_UserLogin
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_Lang_Navi_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_Lang_Navi_User MemAbstractMdl_Get_Gust_NVM_Lang_Navi_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_Main_menu_Select_byte1_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_Main_menu_Select_byte1_User MemAbstractMdl_Get_Gust_NVM_Main_menu_Select_byte1_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_Main_menu_Select_byte2_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_Main_menu_Select_byte2_User MemAbstractMdl_Get_Gust_NVM_Main_menu_Select_byte2_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_OperationGuidance_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_OperationGuidance_User MemAbstractMdl_Get_Gust_NVM_OperationGuidance_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_PersonalDisplay_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_PersonalDisplay_User MemAbstractMdl_Get_Gust_NVM_PersonalDisplay_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_TPMS_Temp_unit_setting_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_TPMS_Temp_unit_setting_User MemAbstractMdl_Get_Gust_NVM_TPMS_Temp_unit_setting_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_Top_layer_contents_User(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_Top_layer_contents_User MemAbstractMdl_Get_Gust_NVM_Top_layer_contents_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_illum_mode_step_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_illum_mode_step_User MemAbstractMdl_Get_Gust_NVM_illum_mode_step_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Gust_NVM_illum_night_step_User(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Gust_NVM_illum_night_step_User MemAbstractMdl_Get_Gust_NVM_illum_night_step_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_IllumMeasuredMaxIntensity(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_IllumMeasuredMaxIntensity MemAbstractMdl_Get_IllumMeasuredMaxIntensity
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_IllumReferenceMaxIntensity(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_IllumReferenceMaxIntensity MemAbstractMdl_Get_IllumReferenceMaxIntensity
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ManufacturingModeRequested(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_ManufacturingModeRequested MemAbstractMdl_Get_ManufacturingModeRequested
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_AlertSettingSave_Key(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_AlertSettingSave_Key(P2VAR(t_uint32_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_AlertSettingSave_Key MemAbstractMdl_Get_NVM_AlertSettingSave_Key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_AlertSetting_User(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_AlertSetting_User(P2VAR(t_uint32_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_AlertSetting_User MemAbstractMdl_Get_NVM_AlertSetting_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Car_color_Eco_Welcome_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Car_color_Eco_Welcome_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Car_color_Eco_Welcome_User MemAbstractMdl_Get_NVM_Car_color_Eco_Welcome_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Car_color_Eco_Welcome_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Car_color_Eco_Welcome_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Car_color_Eco_Welcome_key MemAbstractMdl_Get_NVM_Car_color_Eco_Welcome_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_HM_FaultCounters_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_HM_FaultCounters_Data(P2VAR(t_uint8_x_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_HM_FaultCounters_Data MemAbstractMdl_Get_NVM_HM_FaultCounters_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_KeyId(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_KeyId MemAbstractMdl_Get_NVM_KeyId
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Key_Link_UserLogin(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Key_Link_UserLogin(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Key_Link_UserLogin MemAbstractMdl_Get_NVM_Key_Link_UserLogin
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Key_Link_status(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Key_Link_status(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Key_Link_status MemAbstractMdl_Get_NVM_Key_Link_status
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Lang_Navi_Ikey_link_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Lang_Navi_Ikey_link_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Lang_Navi_Ikey_link_key MemAbstractMdl_Get_NVM_Lang_Navi_Ikey_link_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Lang_Navi_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Lang_Navi_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Lang_Navi_User MemAbstractMdl_Get_NVM_Lang_Navi_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte1_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte1_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Main_menu_Select_byte1_User MemAbstractMdl_Get_NVM_Main_menu_Select_byte1_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte1_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte1_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Main_menu_Select_byte1_key MemAbstractMdl_Get_NVM_Main_menu_Select_byte1_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte2_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte2_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Main_menu_Select_byte2_User MemAbstractMdl_Get_NVM_Main_menu_Select_byte2_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte2_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Main_menu_Select_byte2_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Main_menu_Select_byte2_key MemAbstractMdl_Get_NVM_Main_menu_Select_byte2_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Milage_TPMS_Temp_unit_setting_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Milage_TPMS_Temp_unit_setting_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Milage_TPMS_Temp_unit_setting_User MemAbstractMdl_Get_NVM_Milage_TPMS_Temp_unit_setting_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Milage_TPMS_Temp_unit_setting_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Milage_TPMS_Temp_unit_setting_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Milage_TPMS_Temp_unit_setting_key MemAbstractMdl_Get_NVM_Milage_TPMS_Temp_unit_setting_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_OperationGuidance_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_OperationGuidance_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_OperationGuidance_User MemAbstractMdl_Get_NVM_OperationGuidance_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Operation_Guidance_Key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Operation_Guidance_Key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Operation_Guidance_Key MemAbstractMdl_Get_NVM_Operation_Guidance_Key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_PersonalDisplay_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_PersonalDisplay_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_PersonalDisplay_User MemAbstractMdl_Get_NVM_PersonalDisplay_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Personal_Display_Key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Personal_Display_Key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Personal_Display_Key MemAbstractMdl_Get_NVM_Personal_Display_Key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Sound_Channel_Vol(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Sound_Channel_Vol(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Sound_Channel_Vol MemAbstractMdl_Get_NVM_Sound_Channel_Vol
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Sound_Mixer_Op_Vol(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Sound_Mixer_Op_Vol MemAbstractMdl_Get_NVM_Sound_Mixer_Op_Vol
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Top_layer_contents_User(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Top_layer_contents_User(P2VAR(t_uint32_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Top_layer_contents_User MemAbstractMdl_Get_NVM_Top_layer_contents_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Top_layer_contents_key(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_Top_layer_contents_key(P2VAR(t_uint32_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_Top_layer_contents_key MemAbstractMdl_Get_NVM_Top_layer_contents_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_mode_step_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_mode_step_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_illum_mode_step_User MemAbstractMdl_Get_NVM_illum_mode_step_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_mode_step_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_mode_step_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_illum_mode_step_key MemAbstractMdl_Get_NVM_illum_mode_step_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_night_step_User(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_night_step_User(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_illum_night_step_User MemAbstractMdl_Get_NVM_illum_night_step_User
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_night_step_key(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NVM_illum_night_step_key(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NVM_illum_night_step_key MemAbstractMdl_Get_NVM_illum_night_step_key
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Analog_Measurements_Calibration(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Analog_Measurements_Calibration(P2VAR(t_uint8_x_18, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Analog_Measurements_Calibration MemAbstractMdl_Get_NV_Analog_Measurements_Calibration
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_AssemblyPlantNum(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_AssemblyPlantNum(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_AssemblyPlantNum MemAbstractMdl_Get_NV_AssemblyPlantNum
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Assembly_Manufacturing_date(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Assembly_Manufacturing_date(P2VAR(t_uint8_x_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Assembly_Manufacturing_date MemAbstractMdl_Get_NV_Assembly_Manufacturing_date
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Customer_reference(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Customer_reference(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Customer_reference MemAbstractMdl_Get_NV_Customer_reference
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_100_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_100_Data(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_100_Data MemAbstractMdl_Get_NV_DIAG_DID_100_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_200_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_200_Data(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_200_Data MemAbstractMdl_Get_NV_DIAG_DID_200_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_300_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_300_Data(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_300_Data MemAbstractMdl_Get_NV_DIAG_DID_300_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_310_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_310_Data MemAbstractMdl_Get_NV_DIAG_DID_310_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_400_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_400_Data(P2VAR(t_uint8_x_2, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_400_Data MemAbstractMdl_Get_NV_DIAG_DID_400_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_410_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_410_Data(P2VAR(t_uint8_x_2, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_410_Data MemAbstractMdl_Get_NV_DIAG_DID_410_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_420_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_420_Data MemAbstractMdl_Get_NV_DIAG_DID_420_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_430_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_430_Data MemAbstractMdl_Get_NV_DIAG_DID_430_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_440_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_440_Data MemAbstractMdl_Get_NV_DIAG_DID_440_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_450_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_450_Data MemAbstractMdl_Get_NV_DIAG_DID_450_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_500_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_500_Data MemAbstractMdl_Get_NV_DIAG_DID_500_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_900_Data(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_900_Data MemAbstractMdl_Get_NV_DIAG_DID_900_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_F190_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_F190_Data(P2VAR(t_uint8_x_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_F190_Data MemAbstractMdl_Get_NV_DIAG_DID_F190_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_F1A2_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_F1A2_Data(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_F1A2_Data MemAbstractMdl_Get_NV_DIAG_DID_F1A2_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_FE11_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_DIAG_DID_FE11_Data(P2VAR(t_uint8_x_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_DIAG_DID_FE11_Data MemAbstractMdl_Get_NV_DIAG_DID_FE11_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Correction_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Correction_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Ect_Gauge_Correction_Table_X MemAbstractMdl_Get_NV_Ect_Gauge_Correction_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Correction_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Correction_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Ect_Gauge_Correction_Table_Y MemAbstractMdl_Get_NV_Ect_Gauge_Correction_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Mapping_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Mapping_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Ect_Gauge_Mapping_Table_X MemAbstractMdl_Get_NV_Ect_Gauge_Mapping_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Mapping_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Ect_Gauge_Mapping_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Ect_Gauge_Mapping_Table_Y MemAbstractMdl_Get_NV_Ect_Gauge_Mapping_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_EquippedPCBVisteonPartNum(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_EquippedPCBVisteonPartNum(P2VAR(t_uint8_x_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_EquippedPCBVisteonPartNum MemAbstractMdl_Get_NV_EquippedPCBVisteonPartNum
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Correction_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Correction_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Fuel_Gauge_Correction_Table_X MemAbstractMdl_Get_NV_Fuel_Gauge_Correction_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Correction_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Correction_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Fuel_Gauge_Correction_Table_Y MemAbstractMdl_Get_NV_Fuel_Gauge_Correction_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Mapping_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Mapping_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Fuel_Gauge_Mapping_Table_X MemAbstractMdl_Get_NV_Fuel_Gauge_Mapping_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Mapping_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Fuel_Gauge_Mapping_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Fuel_Gauge_Mapping_Table_Y MemAbstractMdl_Get_NV_Fuel_Gauge_Mapping_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Idle_StopSetting_CltCount(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Idle_StopSetting_CltCount MemAbstractMdl_Get_NV_Idle_StopSetting_CltCount
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Idle_StopSetting_CltData(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Idle_StopSetting_CltData(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Idle_StopSetting_CltData MemAbstractMdl_Get_NV_Idle_StopSetting_CltData
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Idle_StopSetting_VltCount(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Idle_StopSetting_VltCount MemAbstractMdl_Get_NV_Idle_StopSetting_VltCount
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Idle_StopSetting_VltData(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Idle_StopSetting_VltData(P2VAR(t_uint16_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Idle_StopSetting_VltData MemAbstractMdl_Get_NV_Idle_StopSetting_VltData
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_NvM_Revision_Value(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_NvM_Revision_Value MemAbstractMdl_Get_NV_NvM_Revision_Value
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_NvM_Version_Value(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_NvM_Version_Value MemAbstractMdl_Get_NV_NvM_Version_Value
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Odo_Running_Count_Value1(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Odo_Running_Count_Value1 MemAbstractMdl_Get_NV_Odo_Running_Count_Value1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Odo_Running_Count_Value2(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Odo_Running_Count_Value2 MemAbstractMdl_Get_NV_Odo_Running_Count_Value2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Odo_Running_Count_Value3(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Odo_Running_Count_Value3 MemAbstractMdl_Get_NV_Odo_Running_Count_Value3
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Odo_Running_Count_Value4(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Odo_Running_Count_Value4 MemAbstractMdl_Get_NV_Odo_Running_Count_Value4
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Odo_Running_Count_Value5(P2VAR(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Odo_Running_Count_Value5 MemAbstractMdl_Get_NV_Odo_Running_Count_Value5
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PCBSerialNum(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PCBSerialNum(P2VAR(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PCBSerialNum MemAbstractMdl_Get_NV_PCBSerialNum
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMBigLeftPointerCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMBigLeftPointerCalibrationGain MemAbstractMdl_Get_NV_PWMBigLeftPointerCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMBigRightPointerCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMBigRightPointerCalibrationGain MemAbstractMdl_Get_NV_PWMBigRightPointerCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMLeftDialCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMLeftDialCalibrationGain MemAbstractMdl_Get_NV_PWMLeftDialCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMRightDialCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMRightDialCalibrationGain MemAbstractMdl_Get_NV_PWMRightDialCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMSmallLeftPointerCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMSmallLeftPointerCalibrationGain MemAbstractMdl_Get_NV_PWMSmallLeftPointerCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMSmallRightPointerCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMSmallRightPointerCalibrationGain MemAbstractMdl_Get_NV_PWMSmallRightPointerCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMTFTBLCalibration(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMTFTBLCalibration(P2VAR(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMTFTBLCalibration MemAbstractMdl_Get_NV_PWMTFTBLCalibration
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_PWMTFTBLCalibrationGain(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_PWMTFTBLCalibrationGain MemAbstractMdl_Get_NV_PWMTFTBLCalibrationGain
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_ProductVisteonPartNum(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_ProductVisteonPartNum(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_ProductVisteonPartNum MemAbstractMdl_Get_NV_ProductVisteonPartNum
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Correction_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Correction_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_RPM_Gauge_Correction_Table_X MemAbstractMdl_Get_NV_RPM_Gauge_Correction_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Correction_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Correction_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_RPM_Gauge_Correction_Table_Y MemAbstractMdl_Get_NV_RPM_Gauge_Correction_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Mapping_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Mapping_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_RPM_Gauge_Mapping_Table_X MemAbstractMdl_Get_NV_RPM_Gauge_Mapping_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Mapping_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_RPM_Gauge_Mapping_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_RPM_Gauge_Mapping_Table_Y MemAbstractMdl_Get_NV_RPM_Gauge_Mapping_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Reset_Counters_Reading(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Reset_Counters_Reading(P2VAR(t_uint8_x_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Reset_Counters_Reading MemAbstractMdl_Get_NV_Reset_Counters_Reading
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SMDPlantNum(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SMDPlantNum(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SMDPlantNum MemAbstractMdl_Get_NV_SMDPlantNum
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaDataIndexArray(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaDataIndexArray(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaDataIndexArray MemAbstractMdl_Get_NV_SigmaDataIndexArray
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaNumberValueNoTrigger(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaNumberValueNoTrigger MemAbstractMdl_Get_NV_SigmaNumberValueNoTrigger
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_0(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_0(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_0 MemAbstractMdl_Get_NV_SigmaSSD_Data_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_1(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_1(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_1 MemAbstractMdl_Get_NV_SigmaSSD_Data_1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_10(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_10(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_10 MemAbstractMdl_Get_NV_SigmaSSD_Data_10
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_11(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_11(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_11 MemAbstractMdl_Get_NV_SigmaSSD_Data_11
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_12(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_12(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_12 MemAbstractMdl_Get_NV_SigmaSSD_Data_12
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_13(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_13(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_13 MemAbstractMdl_Get_NV_SigmaSSD_Data_13
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_14(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_14(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_14 MemAbstractMdl_Get_NV_SigmaSSD_Data_14
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_15(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_15(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_15 MemAbstractMdl_Get_NV_SigmaSSD_Data_15
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_2(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_2(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_2 MemAbstractMdl_Get_NV_SigmaSSD_Data_2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_3(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_3(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_3 MemAbstractMdl_Get_NV_SigmaSSD_Data_3
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_4(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_4(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_4 MemAbstractMdl_Get_NV_SigmaSSD_Data_4
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_5(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_5(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_5 MemAbstractMdl_Get_NV_SigmaSSD_Data_5
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_6(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_6(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_6 MemAbstractMdl_Get_NV_SigmaSSD_Data_6
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_7(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_7(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_7 MemAbstractMdl_Get_NV_SigmaSSD_Data_7
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_8(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_8(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_8 MemAbstractMdl_Get_NV_SigmaSSD_Data_8
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_9(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_Data_9(P2VAR(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_Data_9 MemAbstractMdl_Get_NV_SigmaSSD_Data_9
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_0(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_0(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_0 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_1(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_1(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_1 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_10(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_10(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_10 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_10
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_11(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_11(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_11 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_11
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_12(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_12(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_12 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_12
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_13(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_13(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_13 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_13
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_14(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_14(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_14 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_14
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_15(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_15(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_15 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_15
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_2(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_2(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_2 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_3(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_3(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_3 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_3
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_4(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_4(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_4 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_4
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_5(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_5(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_5 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_5
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_6(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_6(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_6 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_6
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_7(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_7(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_7 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_7
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_8(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_8(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_8 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_8
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_9(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaSSD_TimeData_9(P2VAR(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaSSD_TimeData_9 MemAbstractMdl_Get_NV_SigmaSSD_TimeData_9
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaStoreNoTriggerDTCIndex(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaStoreNoTriggerDTCIndex MemAbstractMdl_Get_NV_SigmaStoreNoTriggerDTCIndex
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaStoreTriggerDTCIndex(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaStoreTriggerDTCIndex MemAbstractMdl_Get_NV_SigmaStoreTriggerDTCIndex
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaTriggerNumberValue(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaTriggerNumberValue MemAbstractMdl_Get_NV_SigmaTriggerNumberValue
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_0(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_0(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_0 MemAbstractMdl_Get_NV_SigmaVTD_Data_0
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_1(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_1(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_1 MemAbstractMdl_Get_NV_SigmaVTD_Data_1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_10(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_10(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_10 MemAbstractMdl_Get_NV_SigmaVTD_Data_10
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_11(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_11(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_11 MemAbstractMdl_Get_NV_SigmaVTD_Data_11
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_12(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_12(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_12 MemAbstractMdl_Get_NV_SigmaVTD_Data_12
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_13(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_13(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_13 MemAbstractMdl_Get_NV_SigmaVTD_Data_13
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_14(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_14(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_14 MemAbstractMdl_Get_NV_SigmaVTD_Data_14
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_15(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_15(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_15 MemAbstractMdl_Get_NV_SigmaVTD_Data_15
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_2(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_2(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_2 MemAbstractMdl_Get_NV_SigmaVTD_Data_2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_3(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_3(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_3 MemAbstractMdl_Get_NV_SigmaVTD_Data_3
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_4(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_4(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_4 MemAbstractMdl_Get_NV_SigmaVTD_Data_4
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_5(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_5(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_5 MemAbstractMdl_Get_NV_SigmaVTD_Data_5
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_6(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_6(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_6 MemAbstractMdl_Get_NV_SigmaVTD_Data_6
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_7(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_7(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_7 MemAbstractMdl_Get_NV_SigmaVTD_Data_7
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_8(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_8(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_8 MemAbstractMdl_Get_NV_SigmaVTD_Data_8
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_9(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_SigmaVTD_Data_9(P2VAR(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_SigmaVTD_Data_9 MemAbstractMdl_Get_NV_SigmaVTD_Data_9
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Correction_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Correction_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Spd_Gauge_Correction_Table_X MemAbstractMdl_Get_NV_Spd_Gauge_Correction_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Correction_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Correction_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Spd_Gauge_Correction_Table_Y MemAbstractMdl_Get_NV_Spd_Gauge_Correction_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Mapping_Table_X(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Mapping_Table_X(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Spd_Gauge_Mapping_Table_X MemAbstractMdl_Get_NV_Spd_Gauge_Mapping_Table_X
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Mapping_Table_Y(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Spd_Gauge_Mapping_Table_Y(P2VAR(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Spd_Gauge_Mapping_Table_Y MemAbstractMdl_Get_NV_Spd_Gauge_Mapping_Table_Y
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Traceability_Bytes_AC(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Traceability_Bytes_AC MemAbstractMdl_Get_NV_Traceability_Bytes_AC
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Traceability_Bytes_FC(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Traceability_Bytes_FC MemAbstractMdl_Get_NV_Traceability_Bytes_FC
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Traceability_Bytes_FCT(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Traceability_Bytes_FCT MemAbstractMdl_Get_NV_Traceability_Bytes_FCT
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Traceability_Bytes_ICT(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Traceability_Bytes_ICT MemAbstractMdl_Get_NV_Traceability_Bytes_ICT
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Traceability_Bytes_WS2(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Traceability_Bytes_WS2 MemAbstractMdl_Get_NV_Traceability_Bytes_WS2
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_VehicleManufacturerSparePartNumberVIP(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_VehicleManufacturerSparePartNumberVIP(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_VehicleManufacturerSparePartNumberVIP MemAbstractMdl_Get_NV_VehicleManufacturerSparePartNumberVIP
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Visteon_Product_Config_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_Visteon_Product_Config_Data(P2VAR(t_uint8_x_30, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_Visteon_Product_Config_Data MemAbstractMdl_Get_NV_Visteon_Product_Config_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_XFuelValue(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_XFuelValue MemAbstractMdl_Get_NV_XFuelValue
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_YFuelValue(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_YFuelValue MemAbstractMdl_Get_NV_YFuelValue
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_vehicleManufacturerECUHardwareNumber(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_NV_vehicleManufacturerECUHardwareNumber(P2VAR(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_NV_vehicleManufacturerECUHardwareNumber MemAbstractMdl_Get_NV_vehicleManufacturerECUHardwareNumber
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_AccelGuideSpeed_V1Max(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_AccelGuideSpeed_V1Max MemAbstractMdl_Get_Nv_AccelGuideSpeed_V1Max
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_AccelGuideSpeed_V1Min(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_AccelGuideSpeed_V1Min MemAbstractMdl_Get_Nv_AccelGuideSpeed_V1Min
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_AccelGuideSpeed_V2Max(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_AccelGuideSpeed_V2Max MemAbstractMdl_Get_Nv_AccelGuideSpeed_V2Max
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_AccelGuideSpeed_V2Min(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_AccelGuideSpeed_V2Min MemAbstractMdl_Get_Nv_AccelGuideSpeed_V2Min
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_AccelGuideSpeed_V3Min(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_AccelGuideSpeed_V3Min MemAbstractMdl_Get_Nv_AccelGuideSpeed_V3Min
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_AccelGuideSpeed_V3max(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_AccelGuideSpeed_V3max MemAbstractMdl_Get_Nv_AccelGuideSpeed_V3max
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_DayMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_DayMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Dial_DayMode_Type_A_duty MemAbstractMdl_Get_Nv_Dial_DayMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_DayMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_DayMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Dial_DayMode_Type_B_duty MemAbstractMdl_Get_Nv_Dial_DayMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_NightMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_NightMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Dial_NightMode_Type_A_duty MemAbstractMdl_Get_Nv_Dial_NightMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_NightMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Dial_NightMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Dial_NightMode_Type_B_duty MemAbstractMdl_Get_Nv_Dial_NightMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_EcoRank_T1Min_Time(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_EcoRank_T1Min_Time MemAbstractMdl_Get_Nv_EcoRank_T1Min_Time
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_EcoRate_E1_Value(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_EcoRate_E1_Value MemAbstractMdl_Get_Nv_EcoRate_E1_Value
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_EcoRate_E2_Value(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_EcoRate_E2_Value MemAbstractMdl_Get_Nv_EcoRate_E2_Value
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_EcoRate_E3_Value(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_EcoRate_E3_Value MemAbstractMdl_Get_Nv_EcoRate_E3_Value
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_EcoRate_E4_Value(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_EcoRate_E4_Value MemAbstractMdl_Get_Nv_EcoRate_E4_Value
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_CANOut_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_CANOut_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Extern_CANOut_Type_A_duty MemAbstractMdl_Get_Nv_Extern_CANOut_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_CANOut_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_CANOut_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Extern_CANOut_Type_B_duty MemAbstractMdl_Get_Nv_Extern_CANOut_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_Illum_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_Illum_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Extern_Illum_Type_A_duty MemAbstractMdl_Get_Nv_Extern_Illum_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_Illum_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Extern_Illum_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Extern_Illum_Type_B_duty MemAbstractMdl_Get_Nv_Extern_Illum_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_DayMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_DayMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Pointer_DayMode_Type_A_duty MemAbstractMdl_Get_Nv_Pointer_DayMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_DayMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_DayMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Pointer_DayMode_Type_B_duty MemAbstractMdl_Get_Nv_Pointer_DayMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_NightMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_NightMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Pointer_NightMode_Type_A_duty MemAbstractMdl_Get_Nv_Pointer_NightMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_NightMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_Pointer_NightMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_Pointer_NightMode_Type_B_duty MemAbstractMdl_Get_Nv_Pointer_NightMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_RearDoorAlert_T1_Time(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_RearDoorAlert_T1_Time MemAbstractMdl_Get_Nv_RearDoorAlert_T1_Time
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_DayMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_DayMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_SideSw_DayMode_Type_A_duty MemAbstractMdl_Get_Nv_SideSw_DayMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_DayMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_DayMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_SideSw_DayMode_Type_B_duty MemAbstractMdl_Get_Nv_SideSw_DayMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_NightMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_NightMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_SideSw_NightMode_Type_A_duty MemAbstractMdl_Get_Nv_SideSw_NightMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_NightMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_SideSw_NightMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_SideSw_NightMode_Type_B_duty MemAbstractMdl_Get_Nv_SideSw_NightMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_DayMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_DayMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_TFT_DayMode_Type_A_duty MemAbstractMdl_Get_Nv_TFT_DayMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_DayMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_DayMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_TFT_DayMode_Type_B_duty MemAbstractMdl_Get_Nv_TFT_DayMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_NightMode_Type_A_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_NightMode_Type_A_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_TFT_NightMode_Type_A_duty MemAbstractMdl_Get_Nv_TFT_NightMode_Type_A_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_NightMode_Type_B_duty(P2VAR(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Nv_TFT_NightMode_Type_B_duty(P2VAR(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Nv_TFT_NightMode_Type_B_duty MemAbstractMdl_Get_Nv_TFT_NightMode_Type_B_duty
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_PCB_serial_number_AssemblymanufDate(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_PCB_serial_number_AssemblymanufDate(P2VAR(t_uint8_x_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_PCB_serial_number_AssemblymanufDate MemAbstractMdl_Get_PCB_serial_number_AssemblymanufDate
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ProgLimitCntr(P2VAR(UInt16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_ProgLimitCntr MemAbstractMdl_Get_ProgLimitCntr
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Reserved_Health_Management_Data(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Reserved_Health_Management_Data(P2VAR(t_uint8_x_160, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Reserved_Health_Management_Data MemAbstractMdl_Get_Reserved_Health_Management_Data
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_SecurebootCount(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_SecurebootCount MemAbstractMdl_Get_SecurebootCount
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Signature(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Signature(P2VAR(t_uint8_x_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Signature MemAbstractMdl_Get_Signature
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Signature_1(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_Signature_1(P2VAR(t_uint8_x_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_Signature_1 MemAbstractMdl_Get_Signature_1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ValidDTCState(P2VAR(UInt8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_ValidDTCState MemAbstractMdl_Get_ValidDTCState
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ValidDTCState_1(P2VAR(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(Std_ReturnType, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Get_ValidDTCState_1(P2VAR(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_VAR) Ptr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsGet_Get_ValidDTCState_1 MemAbstractMdl_Get_ValidDTCState_1
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BootApplicationRandomNumber_0(UInt32 BootApplicationRandomNumber_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BootApplicationRandomNumber_0(arg1) (MemAbstractMdl_Set_BootApplicationRandomNumber_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BootForcedLoaderModeDetected_0(UInt32 BootForcedLoaderModeDetected_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BootForcedLoaderModeDetected_0(arg1) (MemAbstractMdl_Set_BootForcedLoaderModeDetected_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BootMagicFlag_0(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BootMagicFlag_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BootMagicFlag_0(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) BootMagicFlag_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BootMagicFlag_0(arg1) (MemAbstractMdl_Set_BootMagicFlag_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_BootVehicleStateDetected_0(UInt32 BootVehicleStateDetected_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_BootVehicleStateDetected_0(arg1) (MemAbstractMdl_Set_BootVehicleStateDetected_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CmacAppCount(UInt8 CmacAppCount); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CmacAppCount(arg1) (MemAbstractMdl_Set_CmacAppCount(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CmacFotaCount(UInt8 CmacFotaCount); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CmacFotaCount(arg1) (MemAbstractMdl_Set_CmacFotaCount(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CmacRollbackCount(UInt8 CmacRollbackCount); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CmacRollbackCount(arg1) (MemAbstractMdl_Set_CmacRollbackCount(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CoherencyDTCState(UInt8 CoherencyDTCState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CoherencyDTCState(arg1) (MemAbstractMdl_Set_CoherencyDTCState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CustomerHWReference_number(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) CustomerHWReference_number); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CustomerHWReference_number(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) CustomerHWReference_number); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CustomerHWReference_number(arg1) (MemAbstractMdl_Set_CustomerHWReference_number(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CustomerReference2_number(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) CustomerReference2_number); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CustomerReference2_number(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) CustomerReference2_number); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CustomerReference2_number(arg1) (MemAbstractMdl_Set_CustomerReference2_number(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CustomerReference_number(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) CustomerReference_number); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_CustomerReference_number(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) CustomerReference_number); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_CustomerReference_number(arg1) (MemAbstractMdl_Set_CustomerReference_number(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ECUCompatibilityDTCState(UInt8 ECUCompatibilityDTCState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_ECUCompatibilityDTCState(arg1) (MemAbstractMdl_Set_ECUCompatibilityDTCState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ECUGeneralMemoryFailureDTCState(UInt8 ECUGeneralMemoryFailureDTCState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_ECUGeneralMemoryFailureDTCState(arg1) (MemAbstractMdl_Set_ECUGeneralMemoryFailureDTCState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fingerprint(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fingerprint); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fingerprint(P2CONST(t_uint8_x_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fingerprint); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fingerprint(arg1) (MemAbstractMdl_Set_Fingerprint(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_FotaUpdateStatus_0(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) FotaUpdateStatus_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_FotaUpdateStatus_0(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) FotaUpdateStatus_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_FotaUpdateStatus_0(arg1) (MemAbstractMdl_Set_FotaUpdateStatus_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_FotaUpdateStatus_1(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) FotaUpdateStatus_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_FotaUpdateStatus_1(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) FotaUpdateStatus_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_FotaUpdateStatus_1(arg1) (MemAbstractMdl_Set_FotaUpdateStatus_1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_ActivePartition(UInt8 Fota_ActivePartition); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_ActivePartition(arg1) (MemAbstractMdl_Set_Fota_ActivePartition(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_Att_Cnt(UInt8 Fota_Att_Cnt); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_Att_Cnt(arg1) (MemAbstractMdl_Set_Fota_Att_Cnt(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_CancelCounter(UInt8 Fota_CancelCounter); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_CancelCounter(arg1) (MemAbstractMdl_Set_Fota_CancelCounter(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_ConfigurationSignatureError(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_ConfigurationSignatureError); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_ConfigurationSignatureError(P2CONST(t_uint8_x_6, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_ConfigurationSignatureError); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_ConfigurationSignatureError(arg1) (MemAbstractMdl_Set_Fota_ConfigurationSignatureError(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_Correlator_Id(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_Correlator_Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_Correlator_Id(P2CONST(t_uint8_x_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_Correlator_Id); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_Correlator_Id(arg1) (MemAbstractMdl_Set_Fota_Correlator_Id(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_DecryptionResult(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_DecryptionResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_DecryptionResult(P2CONST(t_uint8_x_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_DecryptionResult); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_DecryptionResult(arg1) (MemAbstractMdl_Set_Fota_DecryptionResult(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_F_virgin(UInt8 Fota_F_virgin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_F_virgin(arg1) (MemAbstractMdl_Set_Fota_F_virgin(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_FlashCompletedAddress(UInt32 Fota_FlashCompletedAddress); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_FlashCompletedAddress(arg1) (MemAbstractMdl_Set_Fota_FlashCompletedAddress(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_GipDtcUpdate(UInt32 Fota_GipDtcUpdate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_GipDtcUpdate(arg1) (MemAbstractMdl_Set_Fota_GipDtcUpdate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_GlobalDtcUpdate(UInt8 Fota_GlobalDtcUpdate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_GlobalDtcUpdate(arg1) (MemAbstractMdl_Set_Fota_GlobalDtcUpdate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_HashValueUpdate(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_HashValueUpdate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_HashValueUpdate(P2CONST(t_uint8_x_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_HashValueUpdate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_HashValueUpdate(arg1) (MemAbstractMdl_Set_Fota_HashValueUpdate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_IVectorData(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_IVectorData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_IVectorData(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_IVectorData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_IVectorData(arg1) (MemAbstractMdl_Set_Fota_IVectorData(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_IncrementalCounter(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_IncrementalCounter); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_IncrementalCounter(P2CONST(t_uint8_x_32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fota_IncrementalCounter); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_IncrementalCounter(arg1) (MemAbstractMdl_Set_Fota_IncrementalCounter(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_Mileage_Flag(UInt8 Fota_Mileage_Flag); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_Mileage_Flag(arg1) (MemAbstractMdl_Set_Fota_Mileage_Flag(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_PreviousState(UInt8 Fota_PreviousState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_PreviousState(arg1) (MemAbstractMdl_Set_Fota_PreviousState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_RebootCompleteFlag(UInt8 Fota_RebootCompleteFlag); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_RebootCompleteFlag(arg1) (MemAbstractMdl_Set_Fota_RebootCompleteFlag(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_RemainingDataSize(UInt32 Fota_RemainingDataSize); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_RemainingDataSize(arg1) (MemAbstractMdl_Set_Fota_RemainingDataSize(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_RollbackCompleteFlag(UInt8 Fota_RollbackCompleteFlag); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_RollbackCompleteFlag(arg1) (MemAbstractMdl_Set_Fota_RollbackCompleteFlag(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_RollbackInprogress(UInt8 Fota_RollbackInprogress); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_RollbackInprogress(arg1) (MemAbstractMdl_Set_Fota_RollbackInprogress(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_State(UInt8 Fota_State); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_State(arg1) (MemAbstractMdl_Set_Fota_State(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_VIPDownloadSkipFlag(UInt8 Fota_VIPDownloadSkipFlag); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_VIPDownloadSkipFlag(arg1) (MemAbstractMdl_Set_Fota_VIPDownloadSkipFlag(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_VipDtcUpdate(UInt32 Fota_VipDtcUpdate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_VipDtcUpdate(arg1) (MemAbstractMdl_Set_Fota_VipDtcUpdate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_Virgin_Flag(UInt8 Fota_Virgin_Flag); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_Virgin_Flag(arg1) (MemAbstractMdl_Set_Fota_Virgin_Flag(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fota_VlanOpenStatus(UInt8 Fota_VlanOpenStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fota_VlanOpenStatus(arg1) (MemAbstractMdl_Set_Fota_VlanOpenStatus(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_A_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_A_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_A_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_A_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_A_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_A_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_A_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_A_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_A_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_A_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_A_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_A_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_B_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_B_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_B_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_B_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_B_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_B_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_B_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_B_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_B_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_B_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_B_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_B_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_C_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_C_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_C_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_C_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_C_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_C_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_C_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_C_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_C_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_C_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_C_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_C_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_D_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_D_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_D_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_D_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_D_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_D_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_D_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_D_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_D_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_D_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_D_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_D_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_E_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_E_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_E_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_E_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_E_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_E_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_E_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_E_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_E_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_E_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_E_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_E_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_H_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_H_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_H_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_H_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_H_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_H_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_H_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_H_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_H_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_H_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_H_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_H_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_I_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_I_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_I_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_I_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_I_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_I_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_I_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_I_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_I_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_I_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_I_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_I_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_J_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_J_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_J_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_J_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_J_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_J_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_J_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_J_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_J_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_J_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_J_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_J_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_K_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_K_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_K_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_K_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_K_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_K_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_K_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_K_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_K_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_K_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_K_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_K_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_L_FLPS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_L_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_L_FLPS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_L_FLPS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_L_FLPS(arg1) (MemAbstractMdl_Set_Fuel_Table_L_FLPS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_L_RADS(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_L_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Fuel_Table_L_RADS(P2CONST(t_uint16_x_12, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Fuel_Table_L_RADS); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Fuel_Table_L_RADS(arg1) (MemAbstractMdl_Set_Fuel_Table_L_RADS(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_GeneralMemoryFailureDTCState(UInt8 GeneralMemoryFailureDTCState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_GeneralMemoryFailureDTCState(arg1) (MemAbstractMdl_Set_GeneralMemoryFailureDTCState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_AlertSetting_User(UInt32 Gust_NVM_AlertSetting_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_AlertSetting_User(arg1) (MemAbstractMdl_Set_Gust_NVM_AlertSetting_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_Car_color_Eco_Welcome_User(UInt8 Gust_NVM_Car_color_Eco_Welcome_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_Car_color_Eco_Welcome_User(arg1) (MemAbstractMdl_Set_Gust_NVM_Car_color_Eco_Welcome_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_Key_Link_UserLogin(UInt8 Gust_NVM_Key_Link_UserLogin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_Key_Link_UserLogin(arg1) (MemAbstractMdl_Set_Gust_NVM_Key_Link_UserLogin(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_Lang_Navi_User(UInt8 Gust_NVM_Lang_Navi_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_Lang_Navi_User(arg1) (MemAbstractMdl_Set_Gust_NVM_Lang_Navi_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_Main_menu_Select_byte1_User(UInt8 Gust_NVM_Main_menu_Select_byte1_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_Main_menu_Select_byte1_User(arg1) (MemAbstractMdl_Set_Gust_NVM_Main_menu_Select_byte1_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_Main_menu_Select_byte2_User(UInt8 Gust_NVM_Main_menu_Select_byte2_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_Main_menu_Select_byte2_User(arg1) (MemAbstractMdl_Set_Gust_NVM_Main_menu_Select_byte2_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_OperationGuidance_User(UInt8 Gust_NVM_OperationGuidance_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_OperationGuidance_User(arg1) (MemAbstractMdl_Set_Gust_NVM_OperationGuidance_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_PersonalDisplay_User(UInt8 Gust_NVM_PersonalDisplay_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_PersonalDisplay_User(arg1) (MemAbstractMdl_Set_Gust_NVM_PersonalDisplay_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_TPMS_Temp_unit_setting_User(UInt8 Gust_NVM_TPMS_Temp_unit_setting_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_TPMS_Temp_unit_setting_User(arg1) (MemAbstractMdl_Set_Gust_NVM_TPMS_Temp_unit_setting_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_Top_layer_contents_User(UInt32 Gust_NVM_Top_layer_contents_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_Top_layer_contents_User(arg1) (MemAbstractMdl_Set_Gust_NVM_Top_layer_contents_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_illum_mode_step_User(UInt8 Gust_NVM_illum_mode_step_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_illum_mode_step_User(arg1) (MemAbstractMdl_Set_Gust_NVM_illum_mode_step_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Gust_NVM_illum_night_step_User(UInt8 Gust_NVM_illum_night_step_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Gust_NVM_illum_night_step_User(arg1) (MemAbstractMdl_Set_Gust_NVM_illum_night_step_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_IllumMeasuredMaxIntensity(UInt16 IllumMeasuredMaxIntensity); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_IllumMeasuredMaxIntensity(arg1) (MemAbstractMdl_Set_IllumMeasuredMaxIntensity(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_IllumReferenceMaxIntensity(UInt16 IllumReferenceMaxIntensity); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_IllumReferenceMaxIntensity(arg1) (MemAbstractMdl_Set_IllumReferenceMaxIntensity(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ManufacturingModeRequested(UInt16 ManufacturingModeRequested); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_ManufacturingModeRequested(arg1) (MemAbstractMdl_Set_ManufacturingModeRequested(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_AlertSettingSave_Key(P2CONST(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_AlertSettingSave_Key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_AlertSettingSave_Key(P2CONST(t_uint32_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_AlertSettingSave_Key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_AlertSettingSave_Key(arg1) (MemAbstractMdl_Set_NVM_AlertSettingSave_Key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_AlertSetting_User(P2CONST(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_AlertSetting_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_AlertSetting_User(P2CONST(t_uint32_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_AlertSetting_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_AlertSetting_User(arg1) (MemAbstractMdl_Set_NVM_AlertSetting_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Car_color_Eco_Welcome_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Car_color_Eco_Welcome_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Car_color_Eco_Welcome_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Car_color_Eco_Welcome_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Car_color_Eco_Welcome_User(arg1) (MemAbstractMdl_Set_NVM_Car_color_Eco_Welcome_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Car_color_Eco_Welcome_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Car_color_Eco_Welcome_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Car_color_Eco_Welcome_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Car_color_Eco_Welcome_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Car_color_Eco_Welcome_key(arg1) (MemAbstractMdl_Set_NVM_Car_color_Eco_Welcome_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_HM_FaultCounters_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_HM_FaultCounters_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_HM_FaultCounters_Data(P2CONST(t_uint8_x_100, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_HM_FaultCounters_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_HM_FaultCounters_Data(arg1) (MemAbstractMdl_Set_NVM_HM_FaultCounters_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_KeyId(UInt8 NVM_KeyId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_KeyId(arg1) (MemAbstractMdl_Set_NVM_KeyId(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Key_Link_UserLogin(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Key_Link_UserLogin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Key_Link_UserLogin(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Key_Link_UserLogin); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Key_Link_UserLogin(arg1) (MemAbstractMdl_Set_NVM_Key_Link_UserLogin(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Key_Link_status(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Key_Link_status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Key_Link_status(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Key_Link_status); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Key_Link_status(arg1) (MemAbstractMdl_Set_NVM_Key_Link_status(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Lang_Navi_Ikey_link_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Lang_Navi_Ikey_link_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Lang_Navi_Ikey_link_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Lang_Navi_Ikey_link_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Lang_Navi_Ikey_link_key(arg1) (MemAbstractMdl_Set_NVM_Lang_Navi_Ikey_link_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Lang_Navi_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Lang_Navi_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Lang_Navi_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Lang_Navi_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Lang_Navi_User(arg1) (MemAbstractMdl_Set_NVM_Lang_Navi_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte1_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte1_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte1_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte1_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Main_menu_Select_byte1_User(arg1) (MemAbstractMdl_Set_NVM_Main_menu_Select_byte1_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte1_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte1_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte1_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte1_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Main_menu_Select_byte1_key(arg1) (MemAbstractMdl_Set_NVM_Main_menu_Select_byte1_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte2_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte2_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte2_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte2_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Main_menu_Select_byte2_User(arg1) (MemAbstractMdl_Set_NVM_Main_menu_Select_byte2_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte2_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte2_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Main_menu_Select_byte2_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Main_menu_Select_byte2_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Main_menu_Select_byte2_key(arg1) (MemAbstractMdl_Set_NVM_Main_menu_Select_byte2_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Milage_TPMS_Temp_unit_setting_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Milage_TPMS_Temp_unit_setting_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Milage_TPMS_Temp_unit_setting_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Milage_TPMS_Temp_unit_setting_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Milage_TPMS_Temp_unit_setting_User(arg1) (MemAbstractMdl_Set_NVM_Milage_TPMS_Temp_unit_setting_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Milage_TPMS_Temp_unit_setting_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Milage_TPMS_Temp_unit_setting_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Milage_TPMS_Temp_unit_setting_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Milage_TPMS_Temp_unit_setting_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Milage_TPMS_Temp_unit_setting_key(arg1) (MemAbstractMdl_Set_NVM_Milage_TPMS_Temp_unit_setting_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_OperationGuidance_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_OperationGuidance_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_OperationGuidance_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_OperationGuidance_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_OperationGuidance_User(arg1) (MemAbstractMdl_Set_NVM_OperationGuidance_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Operation_Guidance_Key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Operation_Guidance_Key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Operation_Guidance_Key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Operation_Guidance_Key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Operation_Guidance_Key(arg1) (MemAbstractMdl_Set_NVM_Operation_Guidance_Key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_PersonalDisplay_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_PersonalDisplay_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_PersonalDisplay_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_PersonalDisplay_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_PersonalDisplay_User(arg1) (MemAbstractMdl_Set_NVM_PersonalDisplay_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Personal_Display_Key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Personal_Display_Key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Personal_Display_Key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Personal_Display_Key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Personal_Display_Key(arg1) (MemAbstractMdl_Set_NVM_Personal_Display_Key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Sound_Channel_Vol(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Sound_Channel_Vol); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Sound_Channel_Vol(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Sound_Channel_Vol); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Sound_Channel_Vol(arg1) (MemAbstractMdl_Set_NVM_Sound_Channel_Vol(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Sound_Mixer_Op_Vol(UInt8 NVM_Sound_Mixer_Op_Vol); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Sound_Mixer_Op_Vol(arg1) (MemAbstractMdl_Set_NVM_Sound_Mixer_Op_Vol(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Top_layer_contents_User(P2CONST(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Top_layer_contents_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Top_layer_contents_User(P2CONST(t_uint32_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Top_layer_contents_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Top_layer_contents_User(arg1) (MemAbstractMdl_Set_NVM_Top_layer_contents_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Top_layer_contents_key(P2CONST(UInt32, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Top_layer_contents_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_Top_layer_contents_key(P2CONST(t_uint32_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_Top_layer_contents_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_Top_layer_contents_key(arg1) (MemAbstractMdl_Set_NVM_Top_layer_contents_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_mode_step_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_mode_step_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_mode_step_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_mode_step_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_illum_mode_step_User(arg1) (MemAbstractMdl_Set_NVM_illum_mode_step_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_mode_step_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_mode_step_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_mode_step_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_mode_step_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_illum_mode_step_key(arg1) (MemAbstractMdl_Set_NVM_illum_mode_step_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_night_step_User(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_night_step_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_night_step_User(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_night_step_User); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_illum_night_step_User(arg1) (MemAbstractMdl_Set_NVM_illum_night_step_User(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_night_step_key(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_night_step_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NVM_illum_night_step_key(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NVM_illum_night_step_key); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NVM_illum_night_step_key(arg1) (MemAbstractMdl_Set_NVM_illum_night_step_key(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Analog_Measurements_Calibration(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Analog_Measurements_Calibration); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Analog_Measurements_Calibration(P2CONST(t_uint8_x_18, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Analog_Measurements_Calibration); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Analog_Measurements_Calibration(arg1) (MemAbstractMdl_Set_NV_Analog_Measurements_Calibration(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_AssemblyPlantNum(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_AssemblyPlantNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_AssemblyPlantNum(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_AssemblyPlantNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_AssemblyPlantNum(arg1) (MemAbstractMdl_Set_NV_AssemblyPlantNum(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Assembly_Manufacturing_date(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Assembly_Manufacturing_date); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Assembly_Manufacturing_date(P2CONST(t_uint8_x_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Assembly_Manufacturing_date); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Assembly_Manufacturing_date(arg1) (MemAbstractMdl_Set_NV_Assembly_Manufacturing_date(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Customer_reference(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Customer_reference); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Customer_reference(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Customer_reference); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Customer_reference(arg1) (MemAbstractMdl_Set_NV_Customer_reference(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_100_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_100_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_100_Data(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_100_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_100_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_100_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_200_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_200_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_200_Data(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_200_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_200_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_200_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_300_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_300_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_300_Data(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_300_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_300_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_300_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_310_Data(UInt8 NV_DIAG_DID_310_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_310_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_310_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_400_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_400_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_400_Data(P2CONST(t_uint8_x_2, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_400_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_400_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_400_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_410_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_410_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_410_Data(P2CONST(t_uint8_x_2, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_410_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_410_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_410_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_420_Data(UInt8 NV_DIAG_DID_420_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_420_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_420_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_430_Data(UInt8 NV_DIAG_DID_430_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_430_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_430_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_440_Data(UInt8 NV_DIAG_DID_440_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_440_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_440_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_450_Data(UInt8 NV_DIAG_DID_450_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_450_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_450_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_500_Data(UInt8 NV_DIAG_DID_500_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_500_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_500_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_900_Data(UInt8 NV_DIAG_DID_900_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_900_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_900_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_F190_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_F190_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_F190_Data(P2CONST(t_uint8_x_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_F190_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_F190_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_F190_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_F1A2_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_F1A2_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_F1A2_Data(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_F1A2_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_F1A2_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_F1A2_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_FE11_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_FE11_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_DIAG_DID_FE11_Data(P2CONST(t_uint8_x_64, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_DIAG_DID_FE11_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_DIAG_DID_FE11_Data(arg1) (MemAbstractMdl_Set_NV_DIAG_DID_FE11_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Correction_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Correction_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Ect_Gauge_Correction_Table_X(arg1) (MemAbstractMdl_Set_NV_Ect_Gauge_Correction_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Correction_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Correction_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Ect_Gauge_Correction_Table_Y(arg1) (MemAbstractMdl_Set_NV_Ect_Gauge_Correction_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Mapping_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Mapping_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Ect_Gauge_Mapping_Table_X(arg1) (MemAbstractMdl_Set_NV_Ect_Gauge_Mapping_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Mapping_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Ect_Gauge_Mapping_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Ect_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Ect_Gauge_Mapping_Table_Y(arg1) (MemAbstractMdl_Set_NV_Ect_Gauge_Mapping_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_EquippedPCBVisteonPartNum(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_EquippedPCBVisteonPartNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_EquippedPCBVisteonPartNum(P2CONST(t_uint8_x_17, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_EquippedPCBVisteonPartNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_EquippedPCBVisteonPartNum(arg1) (MemAbstractMdl_Set_NV_EquippedPCBVisteonPartNum(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Correction_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Correction_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Fuel_Gauge_Correction_Table_X(arg1) (MemAbstractMdl_Set_NV_Fuel_Gauge_Correction_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Correction_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Correction_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Fuel_Gauge_Correction_Table_Y(arg1) (MemAbstractMdl_Set_NV_Fuel_Gauge_Correction_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Mapping_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Mapping_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Fuel_Gauge_Mapping_Table_X(arg1) (MemAbstractMdl_Set_NV_Fuel_Gauge_Mapping_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Mapping_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Fuel_Gauge_Mapping_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Fuel_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Fuel_Gauge_Mapping_Table_Y(arg1) (MemAbstractMdl_Set_NV_Fuel_Gauge_Mapping_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Idle_StopSetting_CltCount(UInt8 NV_Idle_StopSetting_CltCount); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Idle_StopSetting_CltCount(arg1) (MemAbstractMdl_Set_NV_Idle_StopSetting_CltCount(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Idle_StopSetting_CltData(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Idle_StopSetting_CltData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Idle_StopSetting_CltData(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Idle_StopSetting_CltData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Idle_StopSetting_CltData(arg1) (MemAbstractMdl_Set_NV_Idle_StopSetting_CltData(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Idle_StopSetting_VltCount(UInt16 NV_Idle_StopSetting_VltCount); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Idle_StopSetting_VltCount(arg1) (MemAbstractMdl_Set_NV_Idle_StopSetting_VltCount(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Idle_StopSetting_VltData(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Idle_StopSetting_VltData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Idle_StopSetting_VltData(P2CONST(t_uint16_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Idle_StopSetting_VltData); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Idle_StopSetting_VltData(arg1) (MemAbstractMdl_Set_NV_Idle_StopSetting_VltData(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_NvM_Revision_Value(UInt8 NV_NvM_Revision_Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_NvM_Revision_Value(arg1) (MemAbstractMdl_Set_NV_NvM_Revision_Value(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_NvM_Version_Value(UInt8 NV_NvM_Version_Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_NvM_Version_Value(arg1) (MemAbstractMdl_Set_NV_NvM_Version_Value(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Odo_Running_Count_Value1(UInt32 NV_Odo_Running_Count_Value1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Odo_Running_Count_Value1(arg1) (MemAbstractMdl_Set_NV_Odo_Running_Count_Value1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Odo_Running_Count_Value2(UInt32 NV_Odo_Running_Count_Value2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Odo_Running_Count_Value2(arg1) (MemAbstractMdl_Set_NV_Odo_Running_Count_Value2(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Odo_Running_Count_Value3(UInt32 NV_Odo_Running_Count_Value3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Odo_Running_Count_Value3(arg1) (MemAbstractMdl_Set_NV_Odo_Running_Count_Value3(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Odo_Running_Count_Value4(UInt32 NV_Odo_Running_Count_Value4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Odo_Running_Count_Value4(arg1) (MemAbstractMdl_Set_NV_Odo_Running_Count_Value4(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Odo_Running_Count_Value5(UInt32 NV_Odo_Running_Count_Value5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Odo_Running_Count_Value5(arg1) (MemAbstractMdl_Set_NV_Odo_Running_Count_Value5(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PCBSerialNum(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_PCBSerialNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PCBSerialNum(P2CONST(t_uint8_x_5, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_PCBSerialNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PCBSerialNum(arg1) (MemAbstractMdl_Set_NV_PCBSerialNum(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMBigLeftPointerCalibrationGain(UInt16 NV_PWMBigLeftPointerCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMBigLeftPointerCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMBigLeftPointerCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMBigRightPointerCalibrationGain(UInt16 NV_PWMBigRightPointerCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMBigRightPointerCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMBigRightPointerCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMLeftDialCalibrationGain(UInt16 NV_PWMLeftDialCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMLeftDialCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMLeftDialCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMRightDialCalibrationGain(UInt16 NV_PWMRightDialCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMRightDialCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMRightDialCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMSmallLeftPointerCalibrationGain(UInt16 NV_PWMSmallLeftPointerCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMSmallLeftPointerCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMSmallLeftPointerCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMSmallRightPointerCalibrationGain(UInt16 NV_PWMSmallRightPointerCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMSmallRightPointerCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMSmallRightPointerCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMTFTBLCalibration(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_PWMTFTBLCalibration); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMTFTBLCalibration(P2CONST(t_uint8_x_4, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_PWMTFTBLCalibration); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMTFTBLCalibration(arg1) (MemAbstractMdl_Set_NV_PWMTFTBLCalibration(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_PWMTFTBLCalibrationGain(UInt16 NV_PWMTFTBLCalibrationGain); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_PWMTFTBLCalibrationGain(arg1) (MemAbstractMdl_Set_NV_PWMTFTBLCalibrationGain(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_ProductVisteonPartNum(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_ProductVisteonPartNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_ProductVisteonPartNum(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_ProductVisteonPartNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_ProductVisteonPartNum(arg1) (MemAbstractMdl_Set_NV_ProductVisteonPartNum(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Correction_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Correction_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_RPM_Gauge_Correction_Table_X(arg1) (MemAbstractMdl_Set_NV_RPM_Gauge_Correction_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Correction_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Correction_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_RPM_Gauge_Correction_Table_Y(arg1) (MemAbstractMdl_Set_NV_RPM_Gauge_Correction_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Mapping_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Mapping_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_RPM_Gauge_Mapping_Table_X(arg1) (MemAbstractMdl_Set_NV_RPM_Gauge_Mapping_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Mapping_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_RPM_Gauge_Mapping_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_RPM_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_RPM_Gauge_Mapping_Table_Y(arg1) (MemAbstractMdl_Set_NV_RPM_Gauge_Mapping_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Reset_Counters_Reading(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Reset_Counters_Reading); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Reset_Counters_Reading(P2CONST(t_uint8_x_8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Reset_Counters_Reading); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Reset_Counters_Reading(arg1) (MemAbstractMdl_Set_NV_Reset_Counters_Reading(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SMDPlantNum(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SMDPlantNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SMDPlantNum(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SMDPlantNum); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SMDPlantNum(arg1) (MemAbstractMdl_Set_NV_SMDPlantNum(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaDataIndexArray(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaDataIndexArray); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaDataIndexArray(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaDataIndexArray); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaDataIndexArray(arg1) (MemAbstractMdl_Set_NV_SigmaDataIndexArray(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaNumberValueNoTrigger(UInt8 NV_SigmaNumberValueNoTrigger); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaNumberValueNoTrigger(arg1) (MemAbstractMdl_Set_NV_SigmaNumberValueNoTrigger(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_0(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_0(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_0(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_1(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_1(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_1(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_10(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_10); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_10(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_10); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_10(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_10(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_11(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_11); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_11(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_11); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_11(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_11(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_12(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_12); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_12(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_12); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_12(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_12(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_13(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_13); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_13(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_13); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_13(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_13(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_14(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_14); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_14(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_14); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_14(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_14(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_15(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_15); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_15(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_15); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_15(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_15(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_2(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_2(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_2(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_2(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_3(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_3(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_3(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_3(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_4(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_4(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_4(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_4(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_5(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_5(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_5(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_5(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_6(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_6); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_6(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_6); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_6(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_6(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_7(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_7); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_7(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_7); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_7(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_7(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_8(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_8(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_8(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_8(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_9(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_9); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_Data_9(P2CONST(t_uint8_x_63, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_Data_9); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_Data_9(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_Data_9(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_0(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_0(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_0(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_1(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_1(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_1(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_10(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_10); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_10(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_10); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_10(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_10(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_11(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_11); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_11(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_11); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_11(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_11(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_12(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_12); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_12(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_12); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_12(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_12(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_13(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_13); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_13(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_13); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_13(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_13(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_14(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_14); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_14(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_14); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_14(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_14(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_15(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_15); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_15(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_15); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_15(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_15(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_2(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_2(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_2(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_2(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_3(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_3(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_3(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_3(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_4(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_4(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_4(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_4(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_5(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_5(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_5(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_5(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_6(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_6); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_6(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_6); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_6(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_6(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_7(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_7); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_7(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_7); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_7(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_7(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_8(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_8(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_8(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_8(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_9(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_9); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaSSD_TimeData_9(P2CONST(t_uint8_x_3, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaSSD_TimeData_9); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaSSD_TimeData_9(arg1) (MemAbstractMdl_Set_NV_SigmaSSD_TimeData_9(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaStoreNoTriggerDTCIndex(UInt8 NV_SigmaStoreNoTriggerDTCIndex); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaStoreNoTriggerDTCIndex(arg1) (MemAbstractMdl_Set_NV_SigmaStoreNoTriggerDTCIndex(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaStoreTriggerDTCIndex(UInt8 NV_SigmaStoreTriggerDTCIndex); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaStoreTriggerDTCIndex(arg1) (MemAbstractMdl_Set_NV_SigmaStoreTriggerDTCIndex(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaTriggerNumberValue(UInt8 NV_SigmaTriggerNumberValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaTriggerNumberValue(arg1) (MemAbstractMdl_Set_NV_SigmaTriggerNumberValue(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_0(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_0(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_0); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_0(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_0(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_1(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_1(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_1(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_10(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_10); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_10(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_10); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_10(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_10(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_11(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_11); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_11(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_11); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_11(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_11(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_12(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_12); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_12(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_12); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_12(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_12(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_13(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_13); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_13(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_13); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_13(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_13(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_14(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_14); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_14(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_14); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_14(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_14(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_15(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_15); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_15(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_15); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_15(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_15(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_2(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_2(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_2(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_2(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_3(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_3(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_3); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_3(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_3(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_4(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_4(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_4); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_4(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_4(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_5(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_5(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_5); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_5(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_5(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_6(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_6); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_6(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_6); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_6(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_6(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_7(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_7); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_7(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_7); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_7(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_7(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_8(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_8(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_8(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_8(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_9(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_9); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_SigmaVTD_Data_9(P2CONST(t_uint8_x_128, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_SigmaVTD_Data_9); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_SigmaVTD_Data_9(arg1) (MemAbstractMdl_Set_NV_SigmaVTD_Data_9(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Correction_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Correction_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Correction_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Spd_Gauge_Correction_Table_X(arg1) (MemAbstractMdl_Set_NV_Spd_Gauge_Correction_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Correction_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Correction_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Correction_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Spd_Gauge_Correction_Table_Y(arg1) (MemAbstractMdl_Set_NV_Spd_Gauge_Correction_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Mapping_Table_X(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Mapping_Table_X(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Mapping_Table_X); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Spd_Gauge_Mapping_Table_X(arg1) (MemAbstractMdl_Set_NV_Spd_Gauge_Mapping_Table_X(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Mapping_Table_Y(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Spd_Gauge_Mapping_Table_Y(P2CONST(t_uint16_x_15, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Spd_Gauge_Mapping_Table_Y); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Spd_Gauge_Mapping_Table_Y(arg1) (MemAbstractMdl_Set_NV_Spd_Gauge_Mapping_Table_Y(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Traceability_Bytes_AC(UInt8 NV_Traceability_Bytes_AC); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Traceability_Bytes_AC(arg1) (MemAbstractMdl_Set_NV_Traceability_Bytes_AC(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Traceability_Bytes_FC(UInt8 NV_Traceability_Bytes_FC); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Traceability_Bytes_FC(arg1) (MemAbstractMdl_Set_NV_Traceability_Bytes_FC(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Traceability_Bytes_FCT(UInt8 NV_Traceability_Bytes_FCT); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Traceability_Bytes_FCT(arg1) (MemAbstractMdl_Set_NV_Traceability_Bytes_FCT(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Traceability_Bytes_ICT(UInt8 NV_Traceability_Bytes_ICT); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Traceability_Bytes_ICT(arg1) (MemAbstractMdl_Set_NV_Traceability_Bytes_ICT(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Traceability_Bytes_WS2(UInt8 NV_Traceability_Bytes_WS2); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Traceability_Bytes_WS2(arg1) (MemAbstractMdl_Set_NV_Traceability_Bytes_WS2(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_VehicleManufacturerSparePartNumberVIP(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_VehicleManufacturerSparePartNumberVIP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_VehicleManufacturerSparePartNumberVIP(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_VehicleManufacturerSparePartNumberVIP); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_VehicleManufacturerSparePartNumberVIP(arg1) (MemAbstractMdl_Set_NV_VehicleManufacturerSparePartNumberVIP(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Visteon_Product_Config_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Visteon_Product_Config_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_Visteon_Product_Config_Data(P2CONST(t_uint8_x_30, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_Visteon_Product_Config_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_Visteon_Product_Config_Data(arg1) (MemAbstractMdl_Set_NV_Visteon_Product_Config_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_XFuelValue(UInt16 NV_XFuelValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_XFuelValue(arg1) (MemAbstractMdl_Set_NV_XFuelValue(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_YFuelValue(UInt16 NV_YFuelValue); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_YFuelValue(arg1) (MemAbstractMdl_Set_NV_YFuelValue(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_vehicleManufacturerECUHardwareNumber(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_vehicleManufacturerECUHardwareNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_NV_vehicleManufacturerECUHardwareNumber(P2CONST(t_uint8_x_10, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) NV_vehicleManufacturerECUHardwareNumber); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_NV_vehicleManufacturerECUHardwareNumber(arg1) (MemAbstractMdl_Set_NV_vehicleManufacturerECUHardwareNumber(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_AccelGuideSpeed_V1Max(UInt8 Nv_AccelGuideSpeed_V1Max); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_AccelGuideSpeed_V1Max(arg1) (MemAbstractMdl_Set_Nv_AccelGuideSpeed_V1Max(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_AccelGuideSpeed_V1Min(UInt8 Nv_AccelGuideSpeed_V1Min); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_AccelGuideSpeed_V1Min(arg1) (MemAbstractMdl_Set_Nv_AccelGuideSpeed_V1Min(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_AccelGuideSpeed_V2Max(UInt8 Nv_AccelGuideSpeed_V2Max); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_AccelGuideSpeed_V2Max(arg1) (MemAbstractMdl_Set_Nv_AccelGuideSpeed_V2Max(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_AccelGuideSpeed_V2Min(UInt8 Nv_AccelGuideSpeed_V2Min); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_AccelGuideSpeed_V2Min(arg1) (MemAbstractMdl_Set_Nv_AccelGuideSpeed_V2Min(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_AccelGuideSpeed_V3Min(UInt8 Nv_AccelGuideSpeed_V3Min); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_AccelGuideSpeed_V3Min(arg1) (MemAbstractMdl_Set_Nv_AccelGuideSpeed_V3Min(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_AccelGuideSpeed_V3max(UInt8 Nv_AccelGuideSpeed_V3max); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_AccelGuideSpeed_V3max(arg1) (MemAbstractMdl_Set_Nv_AccelGuideSpeed_V3max(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_DayMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_DayMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Dial_DayMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_Dial_DayMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_DayMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_DayMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Dial_DayMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_Dial_DayMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_NightMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_NightMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Dial_NightMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_Dial_NightMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_NightMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Dial_NightMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Dial_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Dial_NightMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_Dial_NightMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_EcoRank_T1Min_Time(UInt8 Nv_EcoRank_T1Min_Time); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_EcoRank_T1Min_Time(arg1) (MemAbstractMdl_Set_Nv_EcoRank_T1Min_Time(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_EcoRate_E1_Value(UInt8 Nv_EcoRate_E1_Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_EcoRate_E1_Value(arg1) (MemAbstractMdl_Set_Nv_EcoRate_E1_Value(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_EcoRate_E2_Value(UInt8 Nv_EcoRate_E2_Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_EcoRate_E2_Value(arg1) (MemAbstractMdl_Set_Nv_EcoRate_E2_Value(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_EcoRate_E3_Value(UInt8 Nv_EcoRate_E3_Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_EcoRate_E3_Value(arg1) (MemAbstractMdl_Set_Nv_EcoRate_E3_Value(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_EcoRate_E4_Value(UInt8 Nv_EcoRate_E4_Value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_EcoRate_E4_Value(arg1) (MemAbstractMdl_Set_Nv_EcoRate_E4_Value(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_CANOut_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_CANOut_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_CANOut_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_CANOut_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Extern_CANOut_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_Extern_CANOut_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_CANOut_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_CANOut_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_CANOut_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_CANOut_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Extern_CANOut_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_Extern_CANOut_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_Illum_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_Illum_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_Illum_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_Illum_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Extern_Illum_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_Extern_Illum_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_Illum_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_Illum_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Extern_Illum_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Extern_Illum_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Extern_Illum_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_Extern_Illum_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_DayMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_DayMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Pointer_DayMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_Pointer_DayMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_DayMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_DayMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Pointer_DayMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_Pointer_DayMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_NightMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_NightMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Pointer_NightMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_Pointer_NightMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_NightMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_Pointer_NightMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_Pointer_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_Pointer_NightMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_Pointer_NightMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_RearDoorAlert_T1_Time(UInt16 Nv_RearDoorAlert_T1_Time); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_RearDoorAlert_T1_Time(arg1) (MemAbstractMdl_Set_Nv_RearDoorAlert_T1_Time(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_DayMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_DayMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_SideSw_DayMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_SideSw_DayMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_DayMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_DayMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_SideSw_DayMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_SideSw_DayMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_NightMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_NightMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_SideSw_NightMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_SideSw_NightMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_NightMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_SideSw_NightMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_SideSw_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_SideSw_NightMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_SideSw_NightMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_DayMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_DayMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_DayMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_TFT_DayMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_TFT_DayMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_DayMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_DayMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_DayMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_TFT_DayMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_TFT_DayMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_NightMode_Type_A_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_NightMode_Type_A_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_NightMode_Type_A_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_TFT_NightMode_Type_A_duty(arg1) (MemAbstractMdl_Set_Nv_TFT_NightMode_Type_A_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_NightMode_Type_B_duty(P2CONST(uint16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Nv_TFT_NightMode_Type_B_duty(P2CONST(t_uint16_x_22, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Nv_TFT_NightMode_Type_B_duty); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Nv_TFT_NightMode_Type_B_duty(arg1) (MemAbstractMdl_Set_Nv_TFT_NightMode_Type_B_duty(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_PCB_serial_number_AssemblymanufDate(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) PCB_serial_number_AssemblymanufDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_PCB_serial_number_AssemblymanufDate(P2CONST(t_uint8_x_20, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) PCB_serial_number_AssemblymanufDate); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_PCB_serial_number_AssemblymanufDate(arg1) (MemAbstractMdl_Set_PCB_serial_number_AssemblymanufDate(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ProgLimitCntr(UInt16 ProgLimitCntr); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_ProgLimitCntr(arg1) (MemAbstractMdl_Set_ProgLimitCntr(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Reserved_Health_Management_Data(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Reserved_Health_Management_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Reserved_Health_Management_Data(P2CONST(t_uint8_x_160, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Reserved_Health_Management_Data); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Reserved_Health_Management_Data(arg1) (MemAbstractMdl_Set_Reserved_Health_Management_Data(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_SecurebootCount(UInt8 SecurebootCount); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_SecurebootCount(arg1) (MemAbstractMdl_Set_SecurebootCount(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Signature(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Signature); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Signature(P2CONST(t_uint8_x_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Signature); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Signature(arg1) (MemAbstractMdl_Set_Signature(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Signature_1(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Signature_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_Signature_1(P2CONST(t_uint8_x_256, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) Signature_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_Signature_1(arg1) (MemAbstractMdl_Set_Signature_1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ValidDTCState(UInt8 ValidDTCState); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_ValidDTCState(arg1) (MemAbstractMdl_Set_ValidDTCState(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
#  ifdef RTE_PTR2ARRAYBASETYPE_PASSING
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ValidDTCState_1(P2CONST(uint8, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) ValidDTCState_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  else
FUNC(void, RTE_MEMABSTRACTMDL_APPL_CODE) MemAbstractMdl_Set_ValidDTCState_1(P2CONST(t_uint8_x_16, AUTOMATIC, RTE_MEMABSTRACTMDL_APPL_DATA) ValidDTCState_1); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  endif
#  define RTE_STOP_SEC_MEMABSTRACTMDL_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_MemAbsSet_Set_ValidDTCState_1(arg1) (MemAbstractMdl_Set_ValidDTCState_1(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_CMEETCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CMEETCDD_APPL_CODE) CMeetCdd_RID_DiagAction(teDiagOpStatus OpStatus, UInt16 RIDNum, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Out_RoutineInfo, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) Data, P2VAR(UInt16, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) DataLength, P2VAR(UInt8, AUTOMATIC, RTE_CMEETCDD_APPL_VAR) pNrc, teDIDOperation eOperation); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CMEETCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_CS_RID_DiagAction_RID_DiagAction CMeetCdd_RID_DiagAction
#  define RTE_START_SEC_CFOTACDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CFOTACDD_APPL_CODE) CFotaCdd_FotaSessionResponseStatus(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CFOTACDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_FotaSessionNotify_FotaSessionResponseStatus CFotaCdd_FotaSessionResponseStatus
#  define RTE_START_SEC_CFOTACDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CFOTACDD_APPL_CODE) CFotaCdd_ModeChange_CallBack(P2VAR(UInt8, AUTOMATIC, RTE_CFOTACDD_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CFOTACDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_FotaSessionNotify_ModeChange_CallBack CFotaCdd_ModeChange_CallBack
#  define RTE_START_SEC_CRYPTOCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRYPTOCDD_APPL_CODE) CryptoCdd_RsaEsOaepSha256(UInt8 const* p_PublicModulusPtr_pU8, UInt32 p_PublicModulusLength_U32, UInt8 const* p_PublicExponentPtr_pU8, UInt32 p_PublicExponentLength_U32, UInt8 const* p_PlainTextPtr_pU8, UInt32 p_PlainTextLength_U32, P2VAR(UInt8, AUTOMATIC, RTE_CRYPTOCDD_APPL_VAR) p_CipherTextPtr_pU8, P2VAR(UInt32, AUTOMATIC, RTE_CRYPTOCDD_APPL_VAR) p_CipherTextLength_pU32); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRYPTOCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_RsaEsOaepSha256_RsaEsOaepSha256 CryptoCdd_RsaEsOaepSha256
#  define RTE_START_SEC_CRYPTOCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRYPTOCDD_APPL_CODE) CryptoCdd_RsaSsaPkcs15Sha256(UInt8 const* p_PublicModulusPtr_pU8, UInt32 p_PublicModulusLength_U32, UInt8 const* p_PublicExponentPtr_pU8, UInt32 p_PublicExponentLength_U32, UInt8 const* p_PlainTextPtr_pU8, UInt32 p_PlainTextLength_U32, UInt8 const* p_SigPtr_pU8, UInt32 p_SigLength_U32, P2VAR(UInt8, AUTOMATIC, RTE_CRYPTOCDD_APPL_VAR) p_VerResultPtr_pU8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRYPTOCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_RsaSsaPkcs15Sha256_RsaSsaPkcs15Sha256 CryptoCdd_RsaSsaPkcs15Sha256
#  define RTE_START_SEC_CRYPTOCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_CRYPTOCDD_APPL_CODE) CryptoCdd_RsaSsaPssSha256NoSalt(UInt8 const* p_PublicModulusPtr_pU8, UInt32 p_PublicModulusLength_U32, UInt8 const* p_PublicExponentPtr_pU8, UInt32 p_PublicExponentLength_U32, UInt8 const* p_PlainTextPtr_pU8, UInt32 p_PlainTextLength_U32, UInt8 const* p_SigPtr_pU8, UInt32 p_SigLength_U32, P2VAR(UInt8, AUTOMATIC, RTE_CRYPTOCDD_APPL_VAR) p_VerResultPtr_pU8); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_CRYPTOCDD_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_RsaSsaPssSha256NoSalt_RsaSsaPssSha256NoSalt CryptoCdd_RsaSsaPssSha256NoSalt


# endif /* !defined(RTE_CORE) */


# define DcmExt_START_SEC_CODE
# include "DcmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_DcmExt_MainFunction DcmExt_MainFunction
#  define RTE_RUNNABLE_SecLevel1CmpKey SecLevel1CmpKey
#  define RTE_RUNNABLE_SecLevel1GetSeed SecLevel1GetSeed
# endif

FUNC(void, DcmExt_CODE) DcmExt_MainFunction(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(Std_ReturnType, DcmExt_CODE) SecLevel1CmpKey(Dcm_MsgType Buff, UInt8 SubFunction, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) NegRes, Dcm_SesCtrlType session); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(Std_ReturnType, DcmExt_CODE) SecLevel1GetSeed(Dcm_MsgType Buff, UInt8 SubFunction, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_DCMEXT_APPL_VAR) NegRes, Dcm_SesCtrlType session); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define DcmExt_STOP_SEC_CODE
# include "DcmExt_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_DID_DiagAction_E_NOT_OK (1U)

#  define RTE_E_TI_DcmExt_CmpKey_E_NOT_OK (1U)

#  define RTE_E_TI_DcmExt_Getseed_E_NOT_OK (1U)

#  define RTE_E_TI_DiagEnteryCondStatus_E_NOT_OK (1U)

#  define RTE_E_TI_FotaServiceEntryNotification_E_NOT_OK (1U)

#  define RTE_E_TI_RID_DiagAction_E_NOT_OK (1U)

#  define RTE_E_TI_RsaEsOaepSha256_E_NOT_OK (1U)

#  define RTE_E_TI_RsaSsaPkcs15Sha256_E_NOT_OK (1U)

#  define RTE_E_TI_RsaSsaPssSha256NoSalt_E_NOT_OK (1U)

#  define RTE_E_if_CS_Diagnostics_Service_E_NOT_OK (1U)

#  define RTE_E_if_CS_MemAbsGet_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_DCMEXT_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
