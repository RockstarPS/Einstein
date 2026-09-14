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
 *          File:  Rte_Mdl_SafetyAdapter.h
 *        Config:  BMW.dpa
 *   ECU-Project:  IC
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  Application header file for SW-C <Mdl_SafetyAdapter>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_MDL_SAFETYADAPTER_H
# define _RTE_MDL_SAFETYADAPTER_H

# ifndef RTE_CORE
#  ifdef RTE_APPLICATION_HEADER_FILE
#   error Multiple application header files included.
#  endif
#  define RTE_APPLICATION_HEADER_FILE
#  ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#   define RTE_PTR2ARRAYBASETYPE_PASSING
#  endif
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

/* include files */

# include "Rte_Mdl_SafetyAdapter_Type.h"
# include "Rte_DataHandleType.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * extern declaration of RTE buffers for optimized macro implementation
 *********************************************************************************************************************/
#  define RTE_START_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern VAR(ClusterModes, RTE_VAR_INIT) Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode; /* PRQA S 0850 */ /* MD_MSR_19.8 */

#  define RTE_STOP_SEC_VAR_INIT_UNSPECIFIED
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# endif /* !defined(RTE_CORE) */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

#  define Rte_InitValue_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode (0U)
#  define Rte_InitValue_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode (0U)
#  define Rte_InitValue_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate (0U)
#  define Rte_InitValue_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1 (0U)
#  define Rte_InitValue_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1 (0U)
#  define Rte_InitValue_rp_SR_RxAB_AB (0U)
#  define Rte_InitValue_rp_SR_RxABS_MID_ABS_MID (0U)
#  define Rte_InitValue_rp_SR_RxBHEXIST_BHEXIST (0U)
#  define Rte_InitValue_rp_SR_RxBRK_MID_BRK_MID (0U)
#  define Rte_InitValue_rp_SR_RxB_ABS_B_ABS (0U)
#  define Rte_InitValue_rp_SR_RxB_ALSD_B_ALSD (0U)
#  define Rte_InitValue_rp_SR_RxB_BRKW_B_BRKW (0U)
#  define Rte_InitValue_rp_SR_RxB_BRKW2_B_BRKW2 (0U)
#  define Rte_InitValue_rp_SR_RxB_BRLV_B_BRLV (0U)
#  define Rte_InitValue_rp_SR_RxB_BRLV2_B_BRLV2 (0U)
#  define Rte_InitValue_rp_SR_RxB_BUZZE2_B_BUZZE2 (0U)
#  define Rte_InitValue_rp_SR_RxB_BUZZER_B_BUZZER (0U)
#  define Rte_InitValue_rp_SR_RxB_CPKB_B_CPKB (0U)
#  define Rte_InitValue_rp_SR_RxB_DACIND_B_DACIND (0U)
#  define Rte_InitValue_rp_SR_RxB_DAINDC_B_DAINDC (0U)
#  define Rte_InitValue_rp_SR_RxB_DAINDP_B_DAINDP (0U)
#  define Rte_InitValue_rp_SR_RxB_EBW_B_EBW (0U)
#  define Rte_InitValue_rp_SR_RxB_EBW2_B_EBW2 (0U)
#  define Rte_InitValue_rp_SR_RxB_EPBMID_B_EPBMID (0U)
#  define Rte_InitValue_rp_SR_RxB_EPBWL_B_EPBWL (0U)
#  define Rte_InitValue_rp_SR_RxB_PKBLP_B_PKBLP (0U)
#  define Rte_InitValue_rp_SR_RxDBKLAB_DBKLAB (0U)
#  define Rte_InitValue_rp_SR_RxEBW_MID_EBW_MID (0U)
#  define Rte_InitValue_rp_SR_RxECBEXIST_ECBEXIST (0U)
#  define Rte_InitValue_rp_SR_RxMCBW_MCBW (0U)
#  define Rte_InitValue_rp_SR_RxPBKLAB_PBKLAB (0U)
#  define Rte_InitValue_rp_SR_RxPWIINFO_PWIINFO (0U)
#  define Rte_InitValue_rp_SR_RxSCSACCEL_SCSACCEL (0U)
#  define Rte_InitValue_rp_SR_RxSCSBZR_SCSBZR (0U)
#  define Rte_InitValue_rp_SR_RxSLP_WL_SLP_WL (0U)
#  define Rte_InitValue_rp_SR_RxTRCCONFL_TRCCONFL (0U)
#  define Rte_InitValue_rp_SR_RxTRCCONFR_TRCCONFR (0U)
#  define Rte_InitValue_rp_SR_RxTRCCONRL_TRCCONRL (0U)
#  define Rte_InitValue_rp_SR_RxTRCCONRR_TRCCONRR (0U)
#  define Rte_InitValue_rp_SR_RxTRCOFF_TRCOFF (0U)
#  define Rte_InitValue_rp_SR_RxVSCEXIST_VSCEXIST (0U)
#  define Rte_InitValue_rp_SR_RxVSCOFF_VSCOFF (0U)
#  define Rte_InitValue_rp_ctrlwss_Clustermode_WSSCurrentClusterMode (0U)
# endif


# ifndef RTE_CORE

/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Read_rp_SR_RxAB_AB Rte_Read_Mdl_SafetyAdapter_rp_SR_RxAB_AB
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxAB_AB(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxABS_MID_ABS_MID Rte_Read_Mdl_SafetyAdapter_rp_SR_RxABS_MID_ABS_MID
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxABS_MID_ABS_MID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxBHEXIST_BHEXIST Rte_Read_Mdl_SafetyAdapter_rp_SR_RxBHEXIST_BHEXIST
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxBHEXIST_BHEXIST(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxBRK_MID_BRK_MID Rte_Read_Mdl_SafetyAdapter_rp_SR_RxBRK_MID_BRK_MID
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxBRK_MID_BRK_MID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_ABS_B_ABS Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_ABS_B_ABS
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_ABS_B_ABS(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_ALSD_B_ALSD Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_ALSD_B_ALSD
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_ALSD_B_ALSD(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_BRKW_B_BRKW Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRKW_B_BRKW
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRKW_B_BRKW(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_BRKW2_B_BRKW2 Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRKW2_B_BRKW2
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRKW2_B_BRKW2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_BRLV_B_BRLV Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRLV_B_BRLV
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRLV_B_BRLV(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_BRLV2_B_BRLV2 Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRLV2_B_BRLV2
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BRLV2_B_BRLV2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_BUZZE2_B_BUZZE2 Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BUZZE2_B_BUZZE2
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BUZZE2_B_BUZZE2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_BUZZER_B_BUZZER Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BUZZER_B_BUZZER
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_BUZZER_B_BUZZER(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_CPKB_B_CPKB Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_CPKB_B_CPKB
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_CPKB_B_CPKB(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_DACIND_B_DACIND Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_DACIND_B_DACIND
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_DACIND_B_DACIND(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_DAINDC_B_DAINDC Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_DAINDC_B_DAINDC
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_DAINDC_B_DAINDC(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_DAINDP_B_DAINDP Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_DAINDP_B_DAINDP
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_DAINDP_B_DAINDP(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_EBW_B_EBW Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EBW_B_EBW
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EBW_B_EBW(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_EBW2_B_EBW2 Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EBW2_B_EBW2
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EBW2_B_EBW2(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_EPBMID_B_EPBMID Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EPBMID_B_EPBMID
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EPBMID_B_EPBMID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_EPBWL_B_EPBWL Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EPBWL_B_EPBWL
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_EPBWL_B_EPBWL(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxB_PKBLP_B_PKBLP Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_PKBLP_B_PKBLP
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxB_PKBLP_B_PKBLP(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxDBKLAB_DBKLAB Rte_Read_Mdl_SafetyAdapter_rp_SR_RxDBKLAB_DBKLAB
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxDBKLAB_DBKLAB(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxEBW_MID_EBW_MID Rte_Read_Mdl_SafetyAdapter_rp_SR_RxEBW_MID_EBW_MID
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxEBW_MID_EBW_MID(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxECBEXIST_ECBEXIST Rte_Read_Mdl_SafetyAdapter_rp_SR_RxECBEXIST_ECBEXIST
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxECBEXIST_ECBEXIST(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxMCBW_MCBW Rte_Read_Mdl_SafetyAdapter_rp_SR_RxMCBW_MCBW
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxMCBW_MCBW(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxPBKLAB_PBKLAB Rte_Read_Mdl_SafetyAdapter_rp_SR_RxPBKLAB_PBKLAB
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxPBKLAB_PBKLAB(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxPWIINFO_PWIINFO Rte_Read_Mdl_SafetyAdapter_rp_SR_RxPWIINFO_PWIINFO
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxPWIINFO_PWIINFO(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxSCSACCEL_SCSACCEL Rte_Read_Mdl_SafetyAdapter_rp_SR_RxSCSACCEL_SCSACCEL
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxSCSACCEL_SCSACCEL(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxSCSBZR_SCSBZR Rte_Read_Mdl_SafetyAdapter_rp_SR_RxSCSBZR_SCSBZR
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxSCSBZR_SCSBZR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxSLP_WL_SLP_WL Rte_Read_Mdl_SafetyAdapter_rp_SR_RxSLP_WL_SLP_WL
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxSLP_WL_SLP_WL(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTRCCONFL_TRCCONFL Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONFL_TRCCONFL
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONFL_TRCCONFL(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTRCCONFR_TRCCONFR Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONFR_TRCCONFR
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONFR_TRCCONFR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTRCCONRL_TRCCONRL Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONRL_TRCCONRL
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONRL_TRCCONRL(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTRCCONRR_TRCCONRR Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONRR_TRCCONRR
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCCONRR_TRCCONRR(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxTRCOFF_TRCOFF Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCOFF_TRCOFF
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxTRCOFF_TRCOFF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxVSCEXIST_VSCEXIST Rte_Read_Mdl_SafetyAdapter_rp_SR_RxVSCEXIST_VSCEXIST
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxVSCEXIST_VSCEXIST(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_SR_RxVSCOFF_VSCOFF Rte_Read_Mdl_SafetyAdapter_rp_SR_RxVSCOFF_VSCOFF
#  define Rte_Read_Mdl_SafetyAdapter_rp_SR_RxVSCOFF_VSCOFF(data) (*(data) = 0U, ((Std_ReturnType)RTE_E_UNCONNECTED)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Read_rp_ctrlwss_Clustermode_WSSCurrentClusterMode Rte_Read_Mdl_SafetyAdapter_rp_ctrlwss_Clustermode_WSSCurrentClusterMode
#  define Rte_Read_Mdl_SafetyAdapter_rp_ctrlwss_Clustermode_WSSCurrentClusterMode(data) (*(data) = Rte_Ctrl_WSS_pp_ClusterMode_WSSCurrentClusterMode, ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Write_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
#  define Rte_Write_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode
#  define Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Appmode_SafetyAdapter_AppMode(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode
#  define Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Clustermode_SafetyAdapter_CurrentClusterMode(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate
#  define Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Ign_Substate_SafetyAdapter_Ign_Substate(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1 Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1
#  define Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Voltage_SafetyAdapter_HVSD1(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Write_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1 Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1
#  define Rte_Write_Mdl_SafetyAdapter_pp_SafetyAdapter_Voltage_SafetyAdapter_LVSD1(data) (RTE_E_OK) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (unmapped) for synchronous C/S communication
 *********************************************************************************************************************/
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_ActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_ActivateSilentCommunication ComMExt_CAN_ActivateSilentCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlActivateRx ComMExt_CAN_CommControlActivateRx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlActivateTx ComMExt_CAN_CommControlActivateTx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlDeActivateRx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlDeActivateRx ComMExt_CAN_CommControlDeActivateRx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlDeActivateTx(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlDeActivateTx ComMExt_CAN_CommControlDeActivateTx
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_CommControlSetDone(Boolean PduInitRequest); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_CommControlSetDone(arg1) (ComMExt_CAN_CommControlSetDone(arg1), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_DeActivateSilentCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_DeActivateSilentCommunication ComMExt_CAN_DeActivateSilentCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_GetCurrentComMode(UInt8 Channel, P2VAR(UInt8, AUTOMATIC, RTE_COMMEXT_APPL_VAR) ComMode); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_GetCurrentComMode ComMExt_CAN_GetCurrentComMode
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_ReleaseCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_ReleaseCommunication ComMExt_CAN_ReleaseCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_CAN_RequestCommunication(UInt8 Channel); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_CAN_RequestCommunication ComMExt_CAN_RequestCommunication
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_GetBusOffStatus(UInt8 Channel, P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) BusOffStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_GetBusOffStatus ComMExt_GetBusOffStatus
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_COMMEXT_APPL_CODE) ComMExt_Get_MCAN_ERR_PIN_Status(P2VAR(Boolean, AUTOMATIC, RTE_COMMEXT_APPL_VAR) fl_pin_status_BOOL); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_Get_MCAN_ERR_PIN_Status ComMExt_Get_MCAN_ERR_PIN_Status
#  define RTE_START_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(void, RTE_COMMEXT_APPL_CODE) ComMExt_Init(void); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_COMMEXT_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rpComMExt_Init() (ComMExt_Init(), ((Std_ReturnType)RTE_E_OK)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IOHWab_Din_GetAsyncRawInput IoHwAb_GetAsyncRawInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetInputGroup(IoHwAb_DInGroupIdType InputId, P2VAR(UInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IOHWab_Din_GetInputGroup IoHwAb_GetInputGroup
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) InputSignal, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IOHWab_Din_GetProcessedInput IoHwAb_GetProcessedInput
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawInput(IoHwAb_DInSignalIdType InputId, P2VAR(Boolean, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncInput, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IOHWab_Din_GetSyncRawInput IoHwAb_GetSyncRawInput
#  define Rte_Call_rp_Init_rp_Init_CCtrl_Telltale_Init() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_Init_rp_Init_CView_Telltale_Init() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define Rte_Call_rp_Init_rp_Init_Mdl_Airbag_Init() (RTE_E_UNCONNECTED) /* PRQA S 3453 */ /* MD_MSR_19.7 */
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetAsyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) AsyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IoHwAb_ADC_GetAsyncRawAdc IoHwAb_GetAsyncRawAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetProcessedAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(SInt32, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ProcessedAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IoHwAb_ADC_GetProcessedAdc IoHwAb_GetProcessedAdc
#  define RTE_START_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */
FUNC(Std_ReturnType, RTE_IOHWAB_APPL_CODE) IoHwAb_GetSyncRawAdc(IoHwAb_AdcSignalIdType AdcId, P2VAR(UInt16, AUTOMATIC, RTE_IOHWAB_APPL_VAR) SyncRawAdc, P2VAR(IoHwAb_ErrorType, AUTOMATIC, RTE_IOHWAB_APPL_VAR) ErrorStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
#  define RTE_STOP_SEC_IOHWAB_APPL_CODE
#  include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#  define Rte_Call_rp_IoHwAb_ADC_GetSyncRawAdc IoHwAb_GetSyncRawAdc


# endif /* !defined(RTE_CORE) */


# define Mdl_SafetyAdapter_START_SEC_CODE
# include "Mdl_SafetyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Runnable entities
 *********************************************************************************************************************/

# ifndef RTE_CORE
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_OnDataRx_B_EBW2 Mdl_SafetyAdapter_OnDataRx_B_EBW2
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_OnDataRx_B_PKBLP Mdl_SafetyAdapter_OnDataRx_B_PKBLP
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_OnDataRx_SCSBZR Mdl_SafetyAdapter_OnDataRx_SCSBZR
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_OnDataRx_VSCOFF Mdl_SafetyAdapter_OnDataRx_VSCOFF
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus
#  define RTE_RUNNABLE_Mdl_SafetyAdapter_Task Mdl_SafetyAdapter_Task
# endif

FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_B_EBW2(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_B_PKBLP(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_SCSBZR(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_OnDataRx_VSCOFF(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */
FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_RxCan_SignalClearJustRcvdStatus(tRxSafeSignalId SignalId); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_RxCan_SignalGetJustRcvdStatus(tRxSafeSignalId SignalId, P2VAR(tRxSafeSignalJustRcvdStatus, AUTOMATIC, RTE_MDL_SAFETYADAPTER_APPL_VAR) pJustRcvdStatus); /* PRQA S 0850 */ /* MD_MSR_19.8 */
FUNC(void, Mdl_SafetyAdapter_CODE) Mdl_SafetyAdapter_Task(void); /* PRQA S 0850, 3451 */ /* MD_MSR_19.8, MD_Rte_3451 */

# define Mdl_SafetyAdapter_STOP_SEC_CODE
# include "Mdl_SafetyAdapter_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


# ifndef RTE_CORE
/**********************************************************************************************************************
 * Application errors
 *********************************************************************************************************************/

#  define RTE_E_TI_ComMExt_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetAdc_E_NOT_OK (1U)

#  define RTE_E_TI_IOHWAB_GetDIn_E_NOT_OK (1U)
# endif /* !defined(RTE_CORE) */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_MDL_SAFETYADAPTER_H */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_3451:  MISRA rule: 8.8
     Reason:     Schedulable entities are declared by the RTE and also by the BSW modules.
     Risk:       No functional risk.
     Prevention: Not required.

*/
