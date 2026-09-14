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
 *          File:  TSC_CFltMExt.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Header of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/


/** Client server interfaces */
Std_ReturnType TSC_CFltMExt_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status);
Std_ReturnType TSC_CFltMExt_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status);
Std_ReturnType TSC_CFltMExt_Rte_Call_rp_CS_FltM_ReportFault_FltM_ReportFault(eFltM_FaultIdType FaultId, eFltM_FaultStatusType FaultStatus, UInt8 *LogData, UInt16 LogLength);
Std_ReturnType TSC_CFltMExt_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetChannelStatus(UInt8 Channel, UInt8 *Status);
Std_ReturnType TSC_CFltMExt_Rte_Call_rp_CS_EcuBatteryOutData_EcuBatteryM_GetDIOStatus(UInt8 InputId, UInt8 *Status);
Std_ReturnType TSC_CFltMExt_Rte_Call_rp_CS_FltM_ReportFault_FltM_ReportFault(eFltM_FaultIdType FaultId, eFltM_FaultStatusType FaultStatus, UInt8 *LogData, UInt16 LogLength);




