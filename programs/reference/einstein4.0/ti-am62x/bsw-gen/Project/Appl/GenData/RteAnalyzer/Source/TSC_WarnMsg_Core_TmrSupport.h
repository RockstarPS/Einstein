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
 *          File:  TSC_WarnMsg_Core_TmrSupport.h
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
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Elapsed_Timer_IsElapsed(HTimer hTimer, UInt32 Timeout, Boolean *IsElapsed);
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Start_Timer_Start(HTimer hTimer);
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Started_Timer_IsStarted(HTimer hTimer, Boolean *IsStarted);
Std_ReturnType TSC_WarnMsg_Core_TmrSupport_Rte_Call_rp_CS_TmExt_Timer_Stop_Timer_Stop(HTimer hTimer);




