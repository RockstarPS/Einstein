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
 *          File:  TSC_CCtrl_Telltale.h
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
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(BulbTestStatus *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpHmiReadyState_HMI_ReadyStatus(HMIReadySts_Type *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(TFTIgnBlankSts_T *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTIndex(TT_ENUM_TYPE *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rp_EtmSts_CurrentBulbTestStatus(BulbTestStatus *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpETMBulbTest_CurrentBulbTestStatus(BulbTestStatus *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpHmiReadyState_HMI_ReadyStatus(HMIReadySts_Type *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpIgnBlankOutCheck_IgnBlankOutCheck(TFTIgnBlankSts_T *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpIgnSubstate_IgnitionSubstate(IgntionSubstateType *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTIndex(TT_ENUM_TYPE *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltaleIndexStatus_TTStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Read_rp_EtmSts_CurrentBulbTestStatus(BulbTestStatus *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(const Rte_DT_TTBlinkArray_0 *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(TTFlashMask data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(const Rte_DT_TT_OP_Type_0 *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(const Rte_DT_TT_OP_Type_0 *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTBlinkStatusArray(const Rte_DT_TTBlinkArray_0 *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppBlinkStatusArray_TTdummyDataForTypes(TTFlashMask data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppGetTelltaleStatus_TelltaleFunctionalOpStatus(const Rte_DT_TT_OP_Type_0 *data);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Write_ppTelltaleStatusOP_TelltaleOpArray(const Rte_DT_TT_OP_Type_0 *data);

/** Client server interfaces */
Std_ReturnType TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status);
Std_ReturnType TSC_CCtrl_Telltale_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status);




