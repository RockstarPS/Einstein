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
 *          File:  TSC_Mdl_wAirbag.h
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
Std_ReturnType TSC_Mdl_wAirbag_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Read_rp_Vehiclestate_WSSCurrentVehicleState(VehicleActiveModes *data);

/** Client server interfaces */
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rpUpdateAirbagWarning_UpdateWarningStatus(WarningId WarningCurId, WarningStatus WarningCurStatus, WarningEvent WarningCurEvent, UInt32 WarningPayload);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_GetSignalValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_GetSignalValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignalValue, tSafeRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SetSignalInitValue(tSafeRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SetSignalInitValueU8Arr(tSafeRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SignalClearJustRcvdStatus(tSafeRxSignalId SignalId);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SignalGetJustRcvdStatus(tSafeRxSignalId SignalId, tSafeRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SignalInvalidProcessingControl(tSafeRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SignalMissingProcessingControl(tSafeRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_wAirbag_Rte_Call_rp_CS_CanAdapterSafeRx_RxCan_SignalNRProcessingControl(tSafeRxSignalId SignalId, Boolean Status);




