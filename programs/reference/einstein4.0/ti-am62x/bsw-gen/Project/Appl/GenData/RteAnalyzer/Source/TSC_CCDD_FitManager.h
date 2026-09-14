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
 *          File:  TSC_CCDD_FitManager.h
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
Std_ReturnType TSC_CCDD_FitManager_Rte_Call_rpCS_FitHandler_rpCS_FitHandler_CCDD_BswFit_FaultInjectionHandler(UInt8 StartStopData, UInt8 TestListID, UInt8 *Data);
Std_ReturnType TSC_CCDD_FitManager_Rte_Call_rpCS_FitHandler_rpCS_FitHandler_CCDD_McuFit_FaultInjectionHandler(UInt8 StartStopData, UInt8 TestListID, UInt8 *Data);




