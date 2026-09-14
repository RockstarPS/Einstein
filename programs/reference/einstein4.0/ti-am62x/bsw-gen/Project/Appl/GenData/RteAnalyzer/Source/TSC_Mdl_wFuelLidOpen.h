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
 *          File:  TSC_Mdl_wFuelLidOpen.h
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
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);

/** Client server interfaces */
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rpUpdateFuelLidOpenWarning_UpdateWarningStatus(WarningId WarningCurId, WarningStatus WarningCurStatus, WarningEvent WarningCurEvent, UInt32 WarningPayload);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_wFuelLidOpen_Rte_Call_rp_CS_RxCanAdapterMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);




