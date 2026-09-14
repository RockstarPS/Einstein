/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CComAbsMdl.c
 *        Config:  BMW.dpa
 *     SW-C Type:  CComAbsMdl
 *
 *     Generator:  MICROSAR RTE Generator Version 4.19.0
 *                 RTE Core Version 1.19.0
 *       License:  CBD1800851
 *
 *   Description:  C-Code implementation template for SW-C <CComAbsMdl>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_5.1_777, MD_MSR_5.1_779 */
/* PRQA S 0857 EOF */ /* MD_MSR_1.1_857 */
/* PRQA S 0614 EOF */ /* MD_Rte_TestCode */

/* PRQA S 3109 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3112 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3197 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3198 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3199 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3201 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3203 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3205 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3206 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3218 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3229 EOF */ /* MD_Rte_TestCode */
/* PRQA S 2002 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3334 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3417 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3426 EOF */ /* MD_Rte_TestCode */
/* PRQA S 3453 EOF */ /* MD_Rte_TestCode */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "Rte_CComAbsMdl.h" /* PRQA S 0857 */ /* MD_MSR_1.1_857 */
#include "TSC_CComAbsMdl.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

#include "string.h"

static void CComAbsMdl_TestDefines(void);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * Boolean: Boolean
 * Rte_DT_Arr_u16_7_0: Integer in interval [0...65535]
 * Rte_DT_Arr_u8_100_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_1024_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_10_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_128_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_16_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_17_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_2048_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_256_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_28_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_32_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_3_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_46_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_48_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_61_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_64_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_8_0: Integer in interval [0...255]
 * Rte_DT_Arr_u8_9_0: Integer in interval [0...255]
 * Rte_DT_T_NV_Temperature_Conversion_0: Integer in interval [0...4294967295]
 * UInt16: Integer in interval [0...65535]
 * UInt32: Integer in interval [0...4294967295]
 * UInt8: Integer in interval [0...255]
 *
 * Enumeration Types:
 * ==================
 * ECmpCmd: Enumeration of integer in interval [0...3] with enumerators
 *   eCmpCmd_Init (0U)
 *   eCmpCmd_DeInit (1U)
 *   eCmpCmd_Activate (2U)
 *   eCmpCmd_DeActivate (3U)
 * tRxSignalId: Enumeration of integer in interval [0...12] with enumerators
 *   eDayNightModeIn (0U)
 *   eIllumination_levelIn (1U)
 *   eAmbient_Light_levelIn (2U)
 *   ePowerModeIn (3U)
 *   eTransportModeIn (4U)
 *   eGearModeIn (5U)
 *   eGearRecommendationIn (6U)
 *   eGearIn (7U)
 *   eWarningIn (8U)
 *   eGearStatusIn (9U)
 *   eEngineSpeedIn (10U)
 *   eTurn_Indicator_ControlIn (11U)
 *   eEndOfRxSignal (12U)
 * tRxSignalJustRcvdStatus: Enumeration of integer in interval [0...1] with enumerators
 *   eJust_Received (0U)
 *   eNot_Just_Received (1U)
 * tRxSignalStatus: Enumeration of integer in interval [0...4] with enumerators
 *   eSIGNAL_OK (0U)
 *   eSIGNAL_MISSING (1U)
 *   eSIGNAL_NEVER_RECEIVED (2U)
 *   eSIGNAL_INVALID (4U)
 * tTxSigConfirmStatus: Enumeration of integer in interval [0...2] with enumerators
 *   eTxSigConfirmStatus_Cleared (0U)
 *   eTxSigConfirmStatus_Set (1U)
 *   eTxSigConfirmStatus_NotSupported (2U)
 * tTxSignalId: Enumeration of integer in interval [0...49] with enumerators
 *   eSecureTxByte0Out (0U)
 *   eSecureTxByte1Out (1U)
 *   eSecureTxByte2Out (2U)
 *   eSecureTxByte3Out (3U)
 *   eMAC_TxOut (4U)
 *   eFV_TxOut (5U)
 *   eOdometerOut (6U)
 *   eVehicleSpeedICOut (7U)
 *   eIllumination_PWMOut (8U)
 *   eDebug1_Byte0Out (9U)
 *   eDebug1_Byte1Out (10U)
 *   eDebug1_Byte2Out (11U)
 *   eDebug1_Byte3Out (12U)
 *   eDebug1_Byte4Out (13U)
 *   eDebug1_Byte5Out (14U)
 *   eDebug1_Byte6Out (15U)
 *   eDebug1_Byte7Out (16U)
 *   eDebug2_Byte0Out (17U)
 *   eDebug2_Byte1Out (18U)
 *   eDebug2_Byte2Out (19U)
 *   eDebug2_Byte3Out (20U)
 *   eDebug2_Byte4Out (21U)
 *   eDebug2_Byte5Out (22U)
 *   eDebug2_Byte6Out (23U)
 *   eDebug2_Byte7Out (24U)
 *   eDebug3_Byte0Out (25U)
 *   eDebug3_Byte1Out (26U)
 *   eDebug3_Byte2Out (27U)
 *   eDebug3_Byte3Out (28U)
 *   eDebug3_Byte4Out (29U)
 *   eDebug3_Byte5Out (30U)
 *   eDebug3_Byte6Out (31U)
 *   eDebug3_Byte7Out (32U)
 *   eDebug4_Byte0Out (33U)
 *   eDebug4_Byte1Out (34U)
 *   eDebug4_Byte2Out (35U)
 *   eDebug4_Byte3Out (36U)
 *   eDebug4_Byte4Out (37U)
 *   eDebug4_Byte5Out (38U)
 *   eDebug4_Byte6Out (39U)
 *   eDebug4_Byte7Out (40U)
 *   eDebug5_Byte0Out (41U)
 *   eDebug5_Byte1Out (42U)
 *   eDebug5_Byte2Out (43U)
 *   eDebug5_Byte3Out (44U)
 *   eDebug5_Byte4Out (45U)
 *   eDebug5_Byte5Out (46U)
 *   eDebug5_Byte6Out (47U)
 *   eDebug5_Byte7Out (48U)
 *   eEndOfTxSignal (49U)
 *
 * Array Types:
 * ============
 * Arr_u16_7: Array with 7 element(s) of type Rte_DT_Arr_u16_7_0
 * Arr_u8_10: Array with 10 element(s) of type Rte_DT_Arr_u8_10_0
 * Arr_u8_100: Array with 100 element(s) of type Rte_DT_Arr_u8_100_0
 * Arr_u8_1024: Array with 1024 element(s) of type Rte_DT_Arr_u8_1024_0
 * Arr_u8_128: Array with 128 element(s) of type Rte_DT_Arr_u8_128_0
 * Arr_u8_16: Array with 16 element(s) of type Rte_DT_Arr_u8_16_0
 * Arr_u8_17: Array with 17 element(s) of type Rte_DT_Arr_u8_17_0
 * Arr_u8_2048: Array with 2048 element(s) of type Rte_DT_Arr_u8_2048_0
 * Arr_u8_256: Array with 256 element(s) of type Rte_DT_Arr_u8_256_0
 * Arr_u8_28: Array with 28 element(s) of type Rte_DT_Arr_u8_28_0
 * Arr_u8_3: Array with 3 element(s) of type Rte_DT_Arr_u8_3_0
 * Arr_u8_32: Array with 32 element(s) of type Rte_DT_Arr_u8_32_0
 * Arr_u8_46: Array with 46 element(s) of type Rte_DT_Arr_u8_46_0
 * Arr_u8_48: Array with 48 element(s) of type Rte_DT_Arr_u8_48_0
 * Arr_u8_61: Array with 61 element(s) of type Rte_DT_Arr_u8_61_0
 * Arr_u8_64: Array with 64 element(s) of type Rte_DT_Arr_u8_64_0
 * Arr_u8_8: Array with 8 element(s) of type Rte_DT_Arr_u8_8_0
 * Arr_u8_9: Array with 9 element(s) of type Rte_DT_Arr_u8_9_0
 * T_NV_Temperature_Conversion: Array with 2 element(s) of type Rte_DT_T_NV_Temperature_Conversion_0
 *
 *********************************************************************************************************************/


#define CComAbsMdl_START_SEC_CODE
#include "CComAbsMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_Impl_OnCommand
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Impl_OnCommand> of PortPrototype <pp_CmpLibCmd_CComAbsMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_Impl_OnCommand(ECmpCmd cmdP)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ModeOnCommand_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_Impl_OnCommand_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_Impl_OnCommand(ECmpCmd cmdP) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_Impl_OnCommand (returns application error)
 *********************************************************************************************************************/

  CComAbsMdl_TestDefines();

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_Impl_RxCanMdlMainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 **********************************************************************************************************************
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Rte_DT_Arr_u8_28_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_28_0* is of type Arr_u8_28
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(UInt32 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Rte_DT_Arr_u16_7_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u16_7_0* is of type Arr_u16_7
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(UInt8 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Rte_DT_T_NV_Temperature_Conversion_0 *Ptr)
 *     Argument Ptr: Rte_DT_T_NV_Temperature_Conversion_0* is of type T_NV_Temperature_Conversion
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Rte_DT_Arr_u8_2048_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_2048_0* is of type Arr_u8_2048
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Rte_DT_Arr_u8_1024_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_1024_0* is of type Arr_u8_1024
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Rte_DT_Arr_u8_100_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_100_0* is of type Arr_u8_100
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Rte_DT_Arr_u8_128_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_128_0* is of type Arr_u8_128
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Rte_DT_Arr_u8_61_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_61_0* is of type Arr_u8_61
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Rte_DT_Arr_u8_9_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_9_0* is of type Arr_u8_9
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Rte_DT_Arr_u8_10_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_10_0* is of type Arr_u8_10
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Rte_DT_Arr_u8_3_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_3_0* is of type Arr_u8_3
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Rte_DT_Arr_u8_32_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_32_0* is of type Arr_u8_32
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Rte_DT_Arr_u8_16_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_16_0* is of type Arr_u8_16
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Rte_DT_Arr_u8_48_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_48_0* is of type Arr_u8_48
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Rte_DT_Arr_u8_8_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_8_0* is of type Arr_u8_8
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Rte_DT_Arr_u8_256_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_256_0* is of type Arr_u8_256
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(UInt16 *Ptr)
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Rte_DT_Arr_u8_46_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_46_0* is of type Arr_u8_46
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Rte_DT_Arr_u8_17_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_17_0* is of type Arr_u8_17
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *   Std_ReturnType Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Rte_DT_Arr_u8_64_0 *Ptr)
 *     Argument Ptr: Rte_DT_Arr_u8_64_0* is of type Arr_u8_64
 *     Synchronous Server Invocation. Timeout: None
 *     Returned Application Errors: RTE_E_if_CS_MemAbsGet_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_Impl_RxCanMdlMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_Impl_RxCanMdlMainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_Impl_RxCanMdlMainFunction
 *********************************************************************************************************************/

  Std_ReturnType fct_status;
  boolean fct_error = 0;

  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_28 Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_Ptr = 0U;
  UInt32 Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_Ptr = 0U;
  UInt16 Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_Ptr = 0U;
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u16_7 Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Ptr = {
  0U, 0U
};
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_Ptr = 0U;
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Ptr = 0U;
  UInt8 Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Ptr = 0U;
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_Ptr = {
  0U, 0U
};
  T_NV_Temperature_Conversion Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_Ptr = {
  0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_2048 Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_1024 Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_100 Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_128 Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_61 Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  UInt16 Call_rp_CS_MemAbsGet_Get_BsShare_HWModification_Ptr = 0U;
  Arr_u8_9 Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_10 Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_3 Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber_Ptr = {
  0U, 0U, 0U
};
  Arr_u8_32 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U
};
  Arr_u8_16 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_48 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_8 Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_256 Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  UInt16 Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element_Ptr = 0U;
  Arr_u8_46 Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_17 Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};
  Arr_u8_64 Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element_Ptr = {
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 
  0U, 0U, 0U, 0U, 0U, 0U
};

  /*************************************************
  * Direct Function Accesses
  *************************************************/

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Audio_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_BsConst_Illumination_ReservedByte_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Communication_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Shift_b_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Compensation_Line_Slope_m_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Derating_Backlight_Disable_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Display_Illum_Max_Level_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element(Call_rp_CS_MemAbsGet_Get_BsConst_EngOffTimer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_FuelGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_X_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Lookup_Curve_HotSpot_Coef_Y_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_OilGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_PCB_Temperature_Sensor_Conv_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_PWM_boost_bypass_duty_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_PowerGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Power_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsConst_RealTimeClock_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element(Call_rp_CS_MemAbsGet_Get_BsConst_ServiceReminder_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_SpeedoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TachoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TempGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2(&Call_rp_CS_MemAbsGet_Get_BsConst_Temp_Threshold_Hysteresis_Derating_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy1_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2(Call_rp_CS_MemAbsGet_Get_BsConst_Temperature_Sensor_Conv_SafeCopy2_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element(Call_rp_CS_MemAbsGet_Get_BsConst_TripComputer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsConst_Warning_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element(Call_rp_CS_MemAbsGet_Get_BsCys_Certicificate_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element(Call_rp_CS_MemAbsGet_Get_BsDiag_Dtc_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element(Call_rp_CS_MemAbsGet_Get_BsDiag_ErrorRecord_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Audio_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Communication_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Display_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Gauges_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Illumination_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Odometer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Personalization_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Power_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsReten_RealTimeClock_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Tripcomputer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsReten_Warning_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element(Call_rp_CS_MemAbsGet_Get_BsRt_CusDlt_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_FuelGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Illumination_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Odometer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_OilGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Personalization_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_PowerGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element(Call_rp_CS_MemAbsGet_Get_BsRt_RealTimeClock_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_SpeedoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TachoGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TempGauge_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element(Call_rp_CS_MemAbsGet_Get_BsRt_TripComputer_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element(Call_rp_CS_MemAbsGet_Get_BsRt_Warning_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate(Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyManufacturingDate_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber(Call_rp_CS_MemAbsGet_Get_BsShare_AssemblyPlantNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element(Call_rp_CS_MemAbsGet_Get_BsShare_EcuPartNumber_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_HWModification(&Call_rp_CS_MemAbsGet_Get_BsShare_HWModification_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber(Call_rp_CS_MemAbsGet_Get_BsShare_PCBSerialNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber(Call_rp_CS_MemAbsGet_Get_BsShare_ProductSerialNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate(Call_rp_CS_MemAbsGet_Get_BsShare_SMTManufacturingDate_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber(Call_rp_CS_MemAbsGet_Get_BsShare_SMTPlantNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaFinPrint_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaMode_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotaStatus_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdFotadecrypt_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element(Call_rp_CS_MemAbsGet_Get_BsShare_SwUpdReflash_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element(Call_rp_CS_MemAbsGet_Get_BsShare_VehicleConfig_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element(&Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_EOLEntry_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element(Call_rp_CS_MemAbsGet_Get_BsShare_VisMeet_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber(Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPCBPartNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber(Call_rp_CS_MemAbsGet_Get_BsShare_VisteonPartNumber_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element(Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate1_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }

  fct_status = TSC_CComAbsMdl_Rte_Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element(Call_rp_CS_MemAbsGet_Get_RefCys_Certicificate_Element_Ptr);
  switch (fct_status)
  {
    case RTE_E_OK:
      fct_error = 0;
      break;
    case RTE_E_UNCONNECTED:
      fct_error = 1;
      break;
    case RTE_E_TIMEOUT:
      fct_error = 1;
      break;
    case RTE_E_if_CS_MemAbsGet_E_NOT_OK:
      fct_error = 1;
      break;
  }


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_Impl_TxCanMdlMainFunction
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_Impl_TxCanMdlMainFunction_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_Impl_TxCanMdlMainFunction(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_Impl_TxCanMdlMainFunction
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_GetSignalValue
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_GetSignalValue> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_GetSignalValue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_GetSignalValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_GetSignalValue (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_GetSignalValueU8Arr
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_GetSignalValueU8Arr> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, UInt8 *pSignalValue, tRxSignalStatus *pSignalStatus, UInt32 *pSignalLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_GetSignalValueU8Arr_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_GetSignalValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue, P2VAR(tRxSignalStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalStatus, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_GetSignalValueU8Arr (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SetSignalInitValue
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SetSignalInitValue> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, UInt8 *pSignalValue)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SetSignalInitValue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_SetSignalInitValue(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalValue) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SetSignalInitValue (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SetSignalInitValueU8Arr
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SetSignalInitValueU8Arr> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, UInt8 *pSignaValue, UInt32 *pSignalLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsRx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SetSignalInitValueU8Arr_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_RxCan_SetSignalInitValueU8Arr(tRxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignaValue, P2VAR(UInt32, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pSignalLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SetSignalInitValueU8Arr (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SignalClearJustRcvdStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalClearJustRcvdStatus> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalClearJustRcvdStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalClearJustRcvdStatus(tRxSignalId SignalId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalClearJustRcvdStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SignalGetJustRcvdStatus
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalGetJustRcvdStatus> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, tRxSignalJustRcvdStatus *pJustRcvdStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalGetJustRcvdStatus_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalGetJustRcvdStatus(tRxSignalId SignalId, P2VAR(tRxSignalJustRcvdStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pJustRcvdStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalGetJustRcvdStatus
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SignalInvalidProcessingControl
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalInvalidProcessingControl> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalInvalidProcessingControl_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalInvalidProcessingControl(tRxSignalId SignalId, Boolean Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalInvalidProcessingControl
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SignalMissingProcessingControl
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalMissingProcessingControl> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalMissingProcessingControl_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalMissingProcessingControl(tRxSignalId SignalId, Boolean Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalMissingProcessingControl
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_RxCan_SignalNRProcessingControl
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RxCan_SignalNRProcessingControl> of PortPrototype <pp_CS_RxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalNRProcessingControl_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_RxCan_SignalNRProcessingControl(tRxSignalId SignalId, Boolean Status) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_RxCan_SignalNRProcessingControl
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_TxCan_ClearCanSignalTxConfirmation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TxCan_ClearCanSignalTxConfirmation> of PortPrototype <pp_CS_TxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_ClearCanSignalTxConfirmation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_TxCan_ClearCanSignalTxConfirmation(tTxSignalId SignalId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_ClearCanSignalTxConfirmation
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_TxCan_GetCanSignalTxConfirmation
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TxCan_GetCanSignalTxConfirmation> of PortPrototype <pp_CS_TxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void CComAbsMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, tTxSigConfirmStatus *pStatus)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_GetCanSignalTxConfirmation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CComAbsMdl_CODE) CComAbsMdl_TxCan_GetCanSignalTxConfirmation(tTxSignalId SignalId, P2VAR(tTxSigConfirmStatus, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pStatus) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_GetCanSignalTxConfirmation
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_TxCan_SetSignalFromRetentionBuffer
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TxCan_SetSignalFromRetentionBuffer> of PortPrototype <pp_CS_TxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_SetSignalFromRetentionBuffer_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_TxCan_SetSignalFromRetentionBuffer(tTxSignalId SignalId) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_SetSignalFromRetentionBuffer (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_TxCan_SetSignalValue
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TxCan_SetSignalValue> of PortPrototype <pp_CS_TxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_TxCan_SetSignalValue(tTxSignalId SignalId, UInt8 *pTxSignalData)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_SetSignalValue_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_TxCan_SetSignalValue(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_SetSignalValue (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: CComAbsMdl_TxCan_SetSignalValueU8Arr
 *
 * This runnable can be invoked concurrently (reentrant implementation).
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <TxCan_SetSignalValueU8Arr> of PortPrototype <pp_CS_TxCanMdl>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType CComAbsMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, UInt8 *pTxSignalData, UInt32 SignalLength)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_if_CS_ComAbsTx_E_NOT_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_SetSignalValueU8Arr_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, CComAbsMdl_CODE) CComAbsMdl_TxCan_SetSignalValueU8Arr(tTxSignalId SignalId, P2VAR(UInt8, AUTOMATIC, RTE_CCOMABSMDL_APPL_VAR) pTxSignalData, UInt32 SignalLength) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: CComAbsMdl_TxCan_SetSignalValueU8Arr (returns application error)
 *********************************************************************************************************************/

  return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CComAbsMdl_STOP_SEC_CODE
#include "CComAbsMdl_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

static void CComAbsMdl_TestDefines(void)
{
  /* Enumeration Data Types */

  ECmpCmd Test_ECmpCmd_V_1 = eCmpCmd_Init;
  ECmpCmd Test_ECmpCmd_V_2 = eCmpCmd_DeInit;
  ECmpCmd Test_ECmpCmd_V_3 = eCmpCmd_Activate;
  ECmpCmd Test_ECmpCmd_V_4 = eCmpCmd_DeActivate;

  tRxSignalId Test_tRxSignalId_V_1 = eDayNightModeIn;
  tRxSignalId Test_tRxSignalId_V_2 = eIllumination_levelIn;
  tRxSignalId Test_tRxSignalId_V_3 = eAmbient_Light_levelIn;
  tRxSignalId Test_tRxSignalId_V_4 = ePowerModeIn;
  tRxSignalId Test_tRxSignalId_V_5 = eTransportModeIn;
  tRxSignalId Test_tRxSignalId_V_6 = eGearModeIn;
  tRxSignalId Test_tRxSignalId_V_7 = eGearRecommendationIn;
  tRxSignalId Test_tRxSignalId_V_8 = eGearIn;
  tRxSignalId Test_tRxSignalId_V_9 = eWarningIn;
  tRxSignalId Test_tRxSignalId_V_10 = eGearStatusIn;
  tRxSignalId Test_tRxSignalId_V_11 = eEngineSpeedIn;
  tRxSignalId Test_tRxSignalId_V_12 = eTurn_Indicator_ControlIn;
  tRxSignalId Test_tRxSignalId_V_13 = eEndOfRxSignal;

  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_1 = eJust_Received;
  tRxSignalJustRcvdStatus Test_tRxSignalJustRcvdStatus_V_2 = eNot_Just_Received;

  tRxSignalStatus Test_tRxSignalStatus_V_1 = eSIGNAL_OK;
  tRxSignalStatus Test_tRxSignalStatus_V_2 = eSIGNAL_MISSING;
  tRxSignalStatus Test_tRxSignalStatus_V_3 = eSIGNAL_NEVER_RECEIVED;
  tRxSignalStatus Test_tRxSignalStatus_V_4 = eSIGNAL_INVALID;

  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_1 = eTxSigConfirmStatus_Cleared;
  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_2 = eTxSigConfirmStatus_Set;
  tTxSigConfirmStatus Test_tTxSigConfirmStatus_V_3 = eTxSigConfirmStatus_NotSupported;

  tTxSignalId Test_tTxSignalId_V_1 = eSecureTxByte0Out;
  tTxSignalId Test_tTxSignalId_V_2 = eSecureTxByte1Out;
  tTxSignalId Test_tTxSignalId_V_3 = eSecureTxByte2Out;
  tTxSignalId Test_tTxSignalId_V_4 = eSecureTxByte3Out;
  tTxSignalId Test_tTxSignalId_V_5 = eMAC_TxOut;
  tTxSignalId Test_tTxSignalId_V_6 = eFV_TxOut;
  tTxSignalId Test_tTxSignalId_V_7 = eOdometerOut;
  tTxSignalId Test_tTxSignalId_V_8 = eVehicleSpeedICOut;
  tTxSignalId Test_tTxSignalId_V_9 = eIllumination_PWMOut;
  tTxSignalId Test_tTxSignalId_V_10 = eDebug1_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_11 = eDebug1_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_12 = eDebug1_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_13 = eDebug1_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_14 = eDebug1_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_15 = eDebug1_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_16 = eDebug1_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_17 = eDebug1_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_18 = eDebug2_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_19 = eDebug2_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_20 = eDebug2_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_21 = eDebug2_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_22 = eDebug2_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_23 = eDebug2_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_24 = eDebug2_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_25 = eDebug2_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_26 = eDebug3_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_27 = eDebug3_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_28 = eDebug3_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_29 = eDebug3_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_30 = eDebug3_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_31 = eDebug3_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_32 = eDebug3_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_33 = eDebug3_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_34 = eDebug4_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_35 = eDebug4_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_36 = eDebug4_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_37 = eDebug4_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_38 = eDebug4_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_39 = eDebug4_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_40 = eDebug4_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_41 = eDebug4_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_42 = eDebug5_Byte0Out;
  tTxSignalId Test_tTxSignalId_V_43 = eDebug5_Byte1Out;
  tTxSignalId Test_tTxSignalId_V_44 = eDebug5_Byte2Out;
  tTxSignalId Test_tTxSignalId_V_45 = eDebug5_Byte3Out;
  tTxSignalId Test_tTxSignalId_V_46 = eDebug5_Byte4Out;
  tTxSignalId Test_tTxSignalId_V_47 = eDebug5_Byte5Out;
  tTxSignalId Test_tTxSignalId_V_48 = eDebug5_Byte6Out;
  tTxSignalId Test_tTxSignalId_V_49 = eDebug5_Byte7Out;
  tTxSignalId Test_tTxSignalId_V_50 = eEndOfTxSignal;
}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_TestCode:
     Reason:     This justification is used within the generated test code by the Rte Analyzer.
     Risk:       No functional risk.
     Prevention: Not required.

*/
