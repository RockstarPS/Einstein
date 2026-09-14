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
 *          File:  TSC_Mdl_TurnHazard.h
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
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rpCS_ChimeRequest_Chime_Request(EChimeID *data);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rpCS_ChimeVolume_UpdateChimeVolume(UInt8 *data);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rpCS_NvmFlashCustBzr_Nvmdata(UInt8 *data);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES data);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES data);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_TurnL_Sts_LeftIndicatorSts(TurnStates data);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Write_pp_TurnHazard_TurnR_Sts_RightIndicatorSts(TurnStates data);

/** Client server interfaces */
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *AsyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetInputGroup(IoHwAb_DInGroupIdType InputId, UInt32 *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetProcessedInput(IoHwAb_DInSignalIdType InputId, Boolean *InputSignal, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rpCS_IoHwAbInp_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, Boolean *SyncInput, IoHwAb_ErrorType *ErrorStatus);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status);
Std_ReturnType TSC_Mdl_TurnHazard_Rte_Call_rp_CS_CanRx_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status);




