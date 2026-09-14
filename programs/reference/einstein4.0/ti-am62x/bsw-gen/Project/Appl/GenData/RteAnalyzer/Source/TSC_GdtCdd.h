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
 *          File:  TSC_GdtCdd.h
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
Std_ReturnType TSC_GdtCdd_Rte_Call_rp_GdtCddTimer_Start_Timer_Start(HTimer hTimer);
Std_ReturnType TSC_GdtCdd_Rte_Call_rp_GdtCddTimer_getElapsedTime_Timer_GetElapsedTime(HTimer hTimer, UInt32 *ElapsedTime);
Std_ReturnType TSC_GdtCdd_Rte_Call_rp_GdtTimerStop_Timer_Stop(HTimer hTimer);




