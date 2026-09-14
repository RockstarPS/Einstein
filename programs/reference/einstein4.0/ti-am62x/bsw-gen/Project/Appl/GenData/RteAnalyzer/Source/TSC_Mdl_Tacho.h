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
 *          File:  TSC_Mdl_Tacho.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Sender receiver - explicit read services */
Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_Country_Code_Func_CountryCode_Func(CountryCode_FuncType *data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_Dcm_appStop_AppId(IOCtrl_Type *data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_PowerTrain_State_PowerTrain_Flag(UInt8 *data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Read_rp_SPD_SP1_In_Status_SP1_In_Status(UInt16 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Analog_Tacho_Analog_Tacho(UInt16 data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Digital_Tacho_Digital_Tacho(UInt16 data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_NE_Out_CalTachoValue(UInt16 data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Needle_Transparent_Needle_TR(UInt8 data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Revp_Disp_REVP_DISP(Boolean data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_TC_Unit_Digital_TachoUnit(Boolean data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Tacho_RED_Start_RPM_RED_Start_RPM(UInt8 data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Tacho_RPM_MAX_REVP_RPM_MAX(UInt8 data);
Std_ReturnType TSC_Mdl_Tacho_Rte_Write_pp_Tacho_Revp_RPM_REVP_RPM(UInt16 data);

/** Client server interfaces */
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt);
Std_ReturnType TSC_Mdl_Tacho_Rte_Call_rp_NE1_Notify_NE1_Recieve_Notify_Value(UInt16 NE1_SignalVal);




