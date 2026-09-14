/********************************************************************************************************************
 *                                   C O P Y R I G H T                                                               *
 *********************************************************************************************************************
 * Copyright (c) 2019 by Visteon Corporation.       All rights reserved.                                             *
 *                                                                                                                   *
 * NOTICE: This is an unpublished work of authorship, which contains trade secrets.                                  *
 * Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve             *
 * its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States    *
 * or those of any other country that may have jurisdiction, to protect this work as an unpublished work,            *
 * in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its      *
 * rights under all copyright laws to protect this work as a published work, when appropriate.                       *
 * Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it  *
 * without the written authorization of Visteon Corporation.                                                         *
 ********************************************************************************************************************/
/*!*****************************************************************************************************************
 *    @file Com_RteHandles.h
 *    @ingroup ComConfiguration
 *    @brief This files provides the mapping between the RTE generated(Application) Com signals macros and the COM
 *    stack generated Macros.
 ********************************************************************************************************************/
#ifndef COM_RTEHANDLES_H
#define COM_RTEHANDLES_H

/*******************************************************************************************************************
 *   PUBLIC MACRO DEFINITION
 ********************************************************************************************************************/
/********************************************************************************************************************
 *   CAN TX SIGNAL HANDLES
 ********************************************************************************************************************/
/*      < RTE/Application HANLDE >                               < COM  HANDLE >                                   */
#define ComConf_ComSignal_Battery_Voltage_oCluster_Tx_Normal_COM_HS_oCAN00_e5088019_Tx (COM_SIGNAL_BATTERY_VOLTAGE_CLUSTER_TX_NORMAL_COM_HS_512_CAN0_TX)
#define ComConf_ComSignal_VehicleSpeedIC_oCluster_Tx_Normal_COM_MS_oCAN00_1b17fdcc_Tx (COM_SIGNAL_VEHICLESPEEDIC_CLUSTER_TX_NORMAL_COM_MS_513_CAN0_TX)
#define ComConf_ComSignal_Illumination_PWM_oCluster_Tx_Reduced_Com_oCAN00_0a670875_Tx (COM_SIGNAL_ILLUMINATION_PWM_CLUSTER_TX_REDUCED_COM_528_CAN0_TX)
#define ComConf_ComSignal_MAC_Tx_oCluster_Secure_Tx_oCAN00_b83a6da7_Tx (COM_SIGNAL_MAC_TX_CLUSTER_SECURE_TX_768_CAN0_TX)
#define ComConf_ComSignal_Odometer_oCluster_Tx_Normal_COM_LS_oCAN00_3e00d027_Tx (COM_SIGNAL_ODOMETER_CLUSTER_TX_NORMAL_COM_LS_514_CAN0_TX)
#define ComConf_ComSignal_SecureTxByte0_oCluster_Secure_Tx_oCAN00_659a0722_Tx (COM_SIGNAL_SECURETXBYTE0_CLUSTER_SECURE_TX_768_CAN0_TX)
#define ComConf_ComSignal_SecureTxByte1_oCluster_Secure_Tx_oCAN00_0b161c63_Tx (COM_SIGNAL_SECURETXBYTE1_CLUSTER_SECURE_TX_768_CAN0_TX)
#define ComConf_ComSignal_SecureTxByte2_oCluster_Secure_Tx_oCAN00_b88231a0_Tx (COM_SIGNAL_SECURETXBYTE2_CLUSTER_SECURE_TX_768_CAN0_TX)
#define ComConf_ComSignal_SecureTxByte3_oCluster_Secure_Tx_oCAN00_d60e2ae1_Tx (COM_SIGNAL_SECURETXBYTE3_CLUSTER_SECURE_TX_768_CAN0_TX)
#define ComConf_ComSignal_FV_Tx_oCluster_Secure_Tx_oCAN00_f077ac5c_Tx (COM_SIGNAL_FV_TX_CLUSTER_SECURE_TX_768_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte0_oDebug_Frame1_oCAN00_7a3e08ee_Tx (COM_SIGNAL_DEBUG1_BYTE0_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte1_oDebug_Frame1_oCAN00_6d166c2e_Tx (COM_SIGNAL_DEBUG1_BYTE1_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte2_oDebug_Frame1_oCAN00_546ec16e_Tx (COM_SIGNAL_DEBUG1_BYTE2_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte3_oDebug_Frame1_oCAN00_4346a5ae_Tx (COM_SIGNAL_DEBUG1_BYTE3_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte4_oDebug_Frame1_oCAN00_269f9bee_Tx (COM_SIGNAL_DEBUG1_BYTE4_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte5_oDebug_Frame1_oCAN00_31b7ff2e_Tx (COM_SIGNAL_DEBUG1_BYTE5_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte6_oDebug_Frame1_oCAN00_08cf526e_Tx (COM_SIGNAL_DEBUG1_BYTE6_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug1_Byte7_oDebug_Frame1_oCAN00_1fe736ae_Tx (COM_SIGNAL_DEBUG1_BYTE7_DEBUG_FRAME1_1360_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte0_oDebug_Frame2_oCAN00_f66f082a_Tx (COM_SIGNAL_DEBUG2_BYTE0_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte1_oDebug_Frame2_oCAN00_e1476cea_Tx (COM_SIGNAL_DEBUG2_BYTE1_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte2_oDebug_Frame2_oCAN00_d83fc1aa_Tx (COM_SIGNAL_DEBUG2_BYTE2_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte3_oDebug_Frame2_oCAN00_cf17a56a_Tx (COM_SIGNAL_DEBUG2_BYTE3_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte4_oDebug_Frame2_oCAN00_aace9b2a_Tx (COM_SIGNAL_DEBUG2_BYTE4_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte5_oDebug_Frame2_oCAN00_bde6ffea_Tx (COM_SIGNAL_DEBUG2_BYTE5_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte6_oDebug_Frame2_oCAN00_849e52aa_Tx (COM_SIGNAL_DEBUG2_BYTE6_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug2_Byte7_oDebug_Frame2_oCAN00_93b6366a_Tx (COM_SIGNAL_DEBUG2_BYTE7_DEBUG_FRAME2_1361_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte0_oDebug_Frame3_oCAN00_3b70f5a9_Tx (COM_SIGNAL_DEBUG3_BYTE0_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte1_oDebug_Frame3_oCAN00_2c589169_Tx (COM_SIGNAL_DEBUG3_BYTE1_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte2_oDebug_Frame3_oCAN00_15203c29_Tx (COM_SIGNAL_DEBUG3_BYTE2_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte3_oDebug_Frame3_oCAN00_020858e9_Tx (COM_SIGNAL_DEBUG3_BYTE3_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte4_oDebug_Frame3_oCAN00_67d166a9_Tx (COM_SIGNAL_DEBUG3_BYTE4_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte5_oDebug_Frame3_oCAN00_70f90269_Tx (COM_SIGNAL_DEBUG3_BYTE5_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte6_oDebug_Frame3_oCAN00_4981af29_Tx (COM_SIGNAL_DEBUG3_BYTE6_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug3_Byte7_oDebug_Frame3_oCAN00_5ea9cbe9_Tx (COM_SIGNAL_DEBUG3_BYTE7_DEBUG_FRAME3_1362_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte0_oDebug_Frame4_oCAN00_35bc0fe3_Tx (COM_SIGNAL_DEBUG4_BYTE0_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte1_oDebug_Frame4_oCAN00_22946b23_Tx (COM_SIGNAL_DEBUG4_BYTE1_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte2_oDebug_Frame4_oCAN00_1becc663_Tx (COM_SIGNAL_DEBUG4_BYTE2_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte3_oDebug_Frame4_oCAN00_0cc4a2a3_Tx (COM_SIGNAL_DEBUG4_BYTE3_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte4_oDebug_Frame4_oCAN00_691d9ce3_Tx (COM_SIGNAL_DEBUG4_BYTE4_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte5_oDebug_Frame4_oCAN00_7e35f823_Tx (COM_SIGNAL_DEBUG4_BYTE5_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte6_oDebug_Frame4_oCAN00_474d5563_Tx (COM_SIGNAL_DEBUG4_BYTE6_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug4_Byte7_oDebug_Frame4_oCAN00_506531a3_Tx (COM_SIGNAL_DEBUG4_BYTE7_DEBUG_FRAME4_1363_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte0_oDebug_Frame5_oCAN00_f8a3f260_Tx (COM_SIGNAL_DEBUG5_BYTE0_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte1_oDebug_Frame5_oCAN00_ef8b96a0_Tx (COM_SIGNAL_DEBUG5_BYTE1_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte2_oDebug_Frame5_oCAN00_d6f33be0_Tx (COM_SIGNAL_DEBUG5_BYTE2_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte3_oDebug_Frame5_oCAN00_c1db5f20_Tx (COM_SIGNAL_DEBUG5_BYTE3_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte4_oDebug_Frame5_oCAN00_a4026160_Tx (COM_SIGNAL_DEBUG5_BYTE4_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte5_oDebug_Frame5_oCAN00_b32a05a0_Tx (COM_SIGNAL_DEBUG5_BYTE5_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte6_oDebug_Frame5_oCAN00_8a52a8e0_Tx (COM_SIGNAL_DEBUG5_BYTE6_DEBUG_FRAME5_1364_CAN0_TX)
#define ComConf_ComSignal_Debug5_Byte7_oDebug_Frame5_oCAN00_9d7acc20_Tx (COM_SIGNAL_DEBUG5_BYTE7_DEBUG_FRAME5_1364_CAN0_TX)
// **Added by Sujay**to be removed by Abhilash
#define ComConf_ComSignal_CurrentStateIC_oIC_NMPDU_oCAN00_ffb15989_Tx - 0
#define ComConf_ComSignal_Diag_Buffer_Tx_USDT_oDiag_Resp_USDT_oCAN00_3c21528d_Tx - 0
#define ComConf_ComSignal_Diag_Buffer_Tx_UUDT_oDiag_Resp_UUDT_oCAN00_0ee1ff7b_Tx - 0
#define ComConf_ComSignal_PreviousStateIC_oIC_NMPDU_oCAN00_54068aa2_Tx - 0
#define ComConf_ComSignal_UserData1_IC_oIC_NMPDU_oCAN00_7de7a39d_Tx - 0
#define ComConf_ComSignal_UserData2_IC_oIC_NMPDU_oCAN00_06f9217e_Tx - 0
#define ComConf_ComSignal_UserData3_IC_oIC_NMPDU_oCAN00_9923a2e0_Tx - 0
#define ComConf_ComSignal_UserData4_IC_oIC_NMPDU_oCAN00_f0c424b8_Tx - 0
#define ComConf_ComSignal_UserData5_IC_oIC_NMPDU_oCAN00_6f1ea726_Tx - 0






/********************************************************************************************************************
 *   CAN RX SIGNAL HANDLES
 ********************************************************************************************************************/
/*      < RTE/Application HANLDE >                               < COM  HANDLE >                                   */
#define ComConf_ComSignal_Airbag_oABS_oCAN00_d379e7a9_Rx (COM_SIGNAL_AIRBAG_ABS_258_CAN0_RX)
#define ComConf_ComSignal_VehicleSpeedABS_oABS_oCAN00_94c6f8d1_Rx (COM_SIGNAL_VEHICLESPEEDABS_ABS_258_CAN0_RX)
#define ComConf_ComSignal_Alive_101_oABS_oCAN00_a0c1519e_Rx (COM_SIGNAL_ALIVE_101_CAN0_RX)
#define ComConf_ComSignal_CRC_101_oABS_oCAN00_bce9141a_Rx (COM_SIGNAL_CRC_101_CAN0_RX)
#define ComConf_ComSignal_GearMode_oVehicleControl_oCAN00_c0b273e8_Rx (COM_SIGNAL_GEARMODE_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_GearRecommendation_oVehicleControl_oCAN00_f980c505_Rx (COM_SIGNAL_GEARRECOMMENDATION_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_GearStatus_oVehicleControl_oCAN00_db10bc53_Rx (COM_SIGNAL_GEARSTATUS_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_EngineSpeed_oVehicleControl_oCAN00_7eb3f445_Rx (COM_SIGNAL_ENGINESPEED_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_Gear_oVehicleControl_oCAN00_45630abd_Rx (COM_SIGNAL_GEAR_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_PowerMode_oVehicleControl_oCAN00_4caafc19_Rx (COM_SIGNAL_POWERMODE_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_TransportMode_oVehicleControl_oCAN00_b498f884_Rx (COM_SIGNAL_TRANSPORTMODE_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_Warning_oVehicleControl_oCAN00_ee369686_Rx (COM_SIGNAL_WARNING_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_Turn_Indicator_Control_oVehicleControl_oCAN00_b06608e9_Rx (COM_SIGNAL_TURN_INDICATOR_CONTROL_VEHICLECONTROL_256_CAN0_RX)
#define ComConf_ComSignal_Ambient_Light_level_oIllum_control_oCAN00_888fcfad_Rx (COM_SIGNAL_AMBIENT_LIGHT_LEVEL_ILLUM_CONTROL_257_CAN0_RX)
#define ComConf_ComSignal_DayNightMode_oIllum_control_oCAN00_6d11bd91_Rx (COM_SIGNAL_DAYNIGHTMODE_ILLUM_CONTROL_257_CAN0_RX)
#define ComConf_ComSignal_Illumination_level_oIllum_control_oCAN00_f3b042f8_Rx (COM_SIGNAL_ILLUMINATION_LEVEL_ILLUM_CONTROL_257_CAN0_RX)
#define ComConf_ComSignalGroup_SG_ABS_oABS_oCAN00_6681ad27_Rx (COM_SIGNAL_GROUP_ABS_258_CAN0_RX)
#define ComConf_ComSignalGroup_SG_COM_HS_oCluster_Tx_Normal_COM_HS_oCAN00_c9c3ed51_Tx (COM_SIGNAL_GROUP_COM_HS_200_CAN0_TX)
#endif /* COM_RTEHANDLES_H */
/*******************************************************************************************************************
 *                                 END OF FILE                                                                      *
 ********************************************************************************************************************/
