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
 *          File:  TSC_CSwcDispMonSf.c
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Implementation of wrapper software component for Bte-based Rte test cases
 *********************************************************************************************************************/
#include "Rte_CSwcDispMonSf.h"
#include "TSC_CSwcDispMonSf.h"








Std_ReturnType TSC_CSwcDispMonSf_Rte_Read_rp_SigCddSts_win_violation_output(UInt8 *data)
{
  return Rte_Read_rp_SigCddSts_win_violation_output(data);
}




Std_ReturnType TSC_CSwcDispMonSf_Rte_Write_pp_SigData_sig0_port(const SIG_WIN_SETUP_T *data)
{
  return Rte_Write_pp_SigData_sig0_port(data);
}





     /* Client Server Interfaces: */
Std_ReturnType TSC_CSwcDispMonSf_Rte_Call_rp_SigCddCrc_Impl_sig_get_win_crc_data(const SIG_WIN_INFO_T *p_sw_info, SIG_WIN_CRC_RGB_T *p_sw_crc_rgb)
{
  return Rte_Call_rp_SigCddCrc_Impl_sig_get_win_crc_data(p_sw_info, p_sw_crc_rgb);
}


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */













     /* Client Server Interfaces: */


     /* Service calls */


     /* Mode Interfaces */




     /* Trigger Interfaces */

     /* Inter-Runnable variables */







     /* CSwcDispMonSf */
      /* CSwcDispMonSf */



