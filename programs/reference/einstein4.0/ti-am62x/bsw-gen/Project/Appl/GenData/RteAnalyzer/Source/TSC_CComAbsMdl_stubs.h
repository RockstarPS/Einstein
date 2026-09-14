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
 *          File:  TSC_CComAbsMdl_stubs.h
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
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(SG_ABS *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxAlive_101_Alive_101(Alive_101 *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxAmbient_Light_level_Ambient_Light_level(Ambient_Light_level *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxCRC_101_CRC_101(CRC_101 *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxDayNightMode_DayNightMode(DayNightMode *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxEngineSpeed_EngineSpeed(EngineSpeed *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGear_Gear(Gear *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGearMode_GearMode(GearMode *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGearRecommendation_GearRecommendation(GearRecommendation *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxGearStatus_GearStatus(GearStatus *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxIllumination_level_Illumination_level(Illumination_level *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxPowerMode_PowerMode(PowerMode *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxTransportMode_TransportMode(TransportMode *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxTurn_Indicator_Control_Turn_Indicator_Control(Turn_Indicator_Control *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxVehicleSpeedABS_VehicleSpeedABS(VehicleSpeedABS *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Read_rp_SR_RxWarning_Warning(Warning *data);

/** Sender receiver - explicit write services */
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxCurrentStateIC_CurrentStateIC(CurrentStateIC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte0_Debug1_Byte0(Debug1_Byte0 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte1_Debug1_Byte1(Debug1_Byte1 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte2_Debug1_Byte2(Debug1_Byte2 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte3_Debug1_Byte3(Debug1_Byte3 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte4_Debug1_Byte4(Debug1_Byte4 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte5_Debug1_Byte5(Debug1_Byte5 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte6_Debug1_Byte6(Debug1_Byte6 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug1_Byte7_Debug1_Byte7(Debug1_Byte7 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte0_Debug2_Byte0(Debug2_Byte0 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte1_Debug2_Byte1(Debug2_Byte1 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte2_Debug2_Byte2(Debug2_Byte2 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte3_Debug2_Byte3(Debug2_Byte3 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte4_Debug2_Byte4(Debug2_Byte4 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte5_Debug2_Byte5(Debug2_Byte5 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte6_Debug2_Byte6(Debug2_Byte6 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug2_Byte7_Debug2_Byte7(Debug2_Byte7 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte0_Debug3_Byte0(Debug3_Byte0 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte1_Debug3_Byte1(Debug3_Byte1 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte2_Debug3_Byte2(Debug3_Byte2 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte3_Debug3_Byte3(Debug3_Byte3 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte4_Debug3_Byte4(Debug3_Byte4 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte5_Debug3_Byte5(Debug3_Byte5 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte6_Debug3_Byte6(Debug3_Byte6 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug3_Byte7_Debug3_Byte7(Debug3_Byte7 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte0_Debug4_Byte0(Debug4_Byte0 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte1_Debug4_Byte1(Debug4_Byte1 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte2_Debug4_Byte2(Debug4_Byte2 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte3_Debug4_Byte3(Debug4_Byte3 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte4_Debug4_Byte4(Debug4_Byte4 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte5_Debug4_Byte5(Debug4_Byte5 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte6_Debug4_Byte6(Debug4_Byte6 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug4_Byte7_Debug4_Byte7(Debug4_Byte7 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte0_Debug5_Byte0(Debug5_Byte0 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte1_Debug5_Byte1(Debug5_Byte1 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte2_Debug5_Byte2(Debug5_Byte2 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte3_Debug5_Byte3(Debug5_Byte3 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte4_Debug5_Byte4(Debug5_Byte4 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte5_Debug5_Byte5(Debug5_Byte5 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte6_Debug5_Byte6(Debug5_Byte6 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDebug5_Byte7_Debug5_Byte7(Debug5_Byte7 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDiag_Buffer_Tx_USDT_Diag_Buffer_Tx_USDT(const UInt8 *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxDiag_Buffer_Tx_UUDT_Diag_Buffer_Tx_UUDT(const UInt8 *data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxFV_Tx_FV_Tx(FV_Tx data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxIllumination_PWM_Illumination_PWM(Illumination_PWM data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxMAC_Tx_MAC_Tx(MAC_Tx data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxOdometer_Odometer(Odometer data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxPreviousStateIC_PreviousStateIC(PreviousStateIC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte0_SecureTxByte0(SecureTxByte0 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte1_SecureTxByte1(SecureTxByte1 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte2_SecureTxByte2(SecureTxByte2 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxSecureTxByte3_SecureTxByte3(SecureTxByte3 data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData1_IC_UserData1_IC(UserData1_IC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData2_IC_UserData2_IC(UserData2_IC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData3_IC_UserData3_IC(UserData3_IC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData4_IC_UserData4_IC(UserData4_IC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxUserData5_IC_UserData5_IC(UserData5_IC data);
Std_ReturnType TSC_CComAbsMdl_stubs_Rte_Write_pp_SR_TxVehicleSpeedIC_VehicleSpeedIC(VehicleSpeedIC data);

/** Sender receiver - update flag */
boolean TSC_CComAbsMdl_stubs_Rte_IsUpdated_RP_SR_RX_SG_ABS_RP_SR_TX_SG_ABS(void);




