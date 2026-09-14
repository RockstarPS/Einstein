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
 *          File:  TSC_DemApp.h
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
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(UInt8 ClientId);
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(UInt8 OperationCycleId, Dem_OperationCycleStateType CycleState);
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_ClearDTC_DemExt_ClearDTC(UInt8 ClientId);
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_SetEventStatus_DemExt_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);
Std_ReturnType TSC_DemApp_Rte_Call_rp_CS_DemExt_SetOperationCycleState_DemExt_SetOperationCycleState(UInt8 OperationCycleId, Dem_OperationCycleStateType CycleState);




