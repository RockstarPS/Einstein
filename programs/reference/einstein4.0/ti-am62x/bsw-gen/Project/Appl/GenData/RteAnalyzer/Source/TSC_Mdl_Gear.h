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
 *          File:  TSC_Mdl_Gear.h
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
Std_ReturnType TSC_Mdl_Gear_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data);
Std_ReturnType TSC_Mdl_Gear_Rte_Read_rpVehicleAppMode_WSSCurrentVehicleState(VehicleActiveModes *data);
Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);
Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_HMI_Ready_Status_HMI_ReadyStatus(HMIReadySts_Type *data);
Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_PowerTrainState_PowerTrain_Flag(UInt8 *data);
Std_ReturnType TSC_Mdl_Gear_Rte_Read_rp_TT_PRND_blink_TIUpdateIndicatorStatus(UInt8 *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_ShiftPositionDisplay_ShiftPositionDisplay(UInt8 data);
Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shift_ModeInd_ShiftModeIndicator(ShiftPositionInd data);
Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shift_Position_ShiftPosition(ShiftPosition data);
Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shiftpos_ShiftPosIndStatus_ShiftPosIndStatusData(const SShiftPosIndStatus *data);
Std_ReturnType TSC_Mdl_Gear_Rte_Write_pp_Shiftpos_ePRNDL_Status_ShiftPos_Data(const ShiftposData_Type *data);

/** Client server interfaces */
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_CS_RxCanMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_Get_Variant_Cfg_Get_Variant_Config_State(UInt8 VariantID, UInt8 *VariantActiveSt);
Std_ReturnType TSC_Mdl_Gear_Rte_Call_rp_Variant_Status_GetVariant_Status(UInt8 Variant_Ind, UInt8 *Variant_Status);




