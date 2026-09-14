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
 *          File:  TSC_CView_Telltale.h
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
Std_ReturnType TSC_CView_Telltale_Rte_Read_rpBlinkStatusArray_TTBlinkStatusArray(Rte_DT_TTBlinkArray_0 *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rpBlinkStatusArray_TTdummyDataForTypes(TTFlashMask *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rpTelltaleStatusOP_TelltaleOpArray(Rte_DT_TT_OP_Type_0 *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rpTelltlaeStatus_rp_Airbag_TT_Status_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_LeftInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rpTelltlaeStatus_rp_TurnHazard_RightInd_Sts_CurrentTelltaleStatus(TT_OP_STATES *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rp_ClusterMode_WSSCurrentClusterMode(ClusterModes *data);
Std_ReturnType TSC_CView_Telltale_Rte_Read_rp_HMIReady_HMI_ReadyStatus(HMIReadySts_Type *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CView_Telltale_Rte_Write_ppTelltaleSts_TT_StatusData(const STT_Status *data);




