#include "Rte_Type.h"
#include "Rte_Main.h"

VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State = 0U; 

/// hmiSimul_ui stubs
VAR(UInt16, RTE_VAR_INIT) Rte_SpdMdl_tiSR_TISpdMdl_Out_SpdF_Speed = 0U; 
VAR(UInt16, RTE_VAR_INIT) Rte_EngMdl_tiSR_TIEngMdl_Out_TachoF_Tacho = 0U;
VAR(UInt8, RTE_VAR_INIT) Rte_EctMdl_EXT_CoolantTempCValue_EXT_CoolantTempCValue = 0U;
VAR(uint32, RTE_VAR_INIT) Rte_OdoMdl_tiSR_OdoOutMiles_Miles = 0U;


VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B1_TIBtnMdl_State_State = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
//VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B3_TIBtnMdl_State_State = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B4_TIBtnMdl_State_State = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B5_TIBtnMdl_State_State = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B6_TIBtnMdl_State_State = 0U; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(EBtnState, RTE_VAR_INIT) Rte_BtnMdl_ppSR_pBtnState_B7_TIBtnMdl_State_State = 0U;

FUNC(Std_ReturnType, RTE_CODE) Rte_Read_GdtCtrl_tiSR_TrcOut_deTrcOut(P2VAR(sTrcOut, AUTOMATIC, RTE_GDTCTRL_APPL_VAR) data) /* PRQA S 0850, 3673, 1505 */ /* MD_MSR_19.8, MD_Rte_Qac, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

//  *(data) = 0;


  return ret;
}

FUNC(void, TripMdl_CODE) CTripMdl_ResetTrip(void)
{}