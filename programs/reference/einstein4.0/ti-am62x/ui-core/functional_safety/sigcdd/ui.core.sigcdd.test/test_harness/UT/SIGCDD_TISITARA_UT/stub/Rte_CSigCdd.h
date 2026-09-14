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
 *          File:  Rte_CSigCdd.h
 *        Config:  Traveo2.dpa
 *   ECU-Project:  CLU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <CSigCdd>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CSIGCDD_H
#define _RTE_CSIGCDD_H

#include "Rte_Type.h"

#include "system.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#define Sig_Ev_NewConfigReady     ((EventMaskType)64uLL)
/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#ifndef Rte_TypeDef_SIG_WIN_SETUP_T
#define Rte_TypeDef_SIG_WIN_SETUP_T
typedef struct
{
  UINT32 control;       /*!<Bit0 (EnEvalWin)    1: Enable Safety Window, 0: Disable Safety Window */
  UINT16 winsx;         /*!<CRC window start x-14bits */
  UINT16 winsy;         /*!<CRC window start y-14bits */
  UINT16 winex;		    /*!<CRC window end x-14bits */
  UINT16 winey;		    /*!<CRC window end y-14bits */
  UINT32 ref_crc;       /*!<Reference CRC */
}SIG_WIN_SETUP_T;
#endif

#ifndef Rte_TypeDef_SIG_WIN_INFO_T
#define Rte_TypeDef_SIG_WIN_INFO_T
typedef struct
{
  UINT8 sig_unit;
  UINT8 window;
} SIG_WIN_INFO_T;
#endif

#ifndef Rte_TypeDef_SIG_WIN_CRC_RGB_T
#define Rte_TypeDef_SIG_WIN_CRC_RGB_T
typedef struct
{		  
   UINT32 crc;    
}SIG_WIN_CRC_RGB_T;
#endif

/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * API prototypes
 *********************************************************************************************************************/

Std_ReturnType Rte_Read_rp_SigData_sig0_vp_win0(SIG_WIN_SETUP_T * data);
Std_ReturnType Rte_Read_rp_SigData_sig0_vp_win1(SIG_WIN_SETUP_T * data);
Std_ReturnType Rte_Read_rp_SigData_sig0_vp_win2(SIG_WIN_SETUP_T * data);
Std_ReturnType Rte_Read_rp_SigData_sig0_vp_win3(SIG_WIN_SETUP_T * data);

void GetEvent(UINT8 p_task_index, UINT8 *p_event_out_val);
void ClearEvent(UINT8 p_event_out_val);
/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

void CSigCdd_Impl_sig_get_win_crc_data(SIG_WIN_INFO_T const * p_sw_info, SIG_WIN_CRC_RGB_T * p_sw_crc_rgb);

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* _RTE_CSIGCDD_H */


